class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<vector<int>>>> dist(m, 
            vector<vector<vector<int>>>(n, 
                vector<vector<int>>(k + 1, 
                    vector<int>(4, 1e9))));

        // KEY FIX #1: cost must be FIRST in the tuple, since that's what
        // Dijkstra needs to prioritize — we always want to expand the
        // globally cheapest known state next, not the fewest-turns one.
        // Sorting by turns first breaks the greedy cost-ordering guarantee
        // and causes far more redundant relaxations.
        //
        // KEY FIX #2: array<int,5> instead of vector<int> — fixed-size,
        // no heap allocation per push/pop, much faster for large state counts.
        using State = array<int,5>; // {cost, turns, dir, i, j}
        priority_queue<State, vector<State>, greater<State>> pq;

        pq.push({grid[0][0], 0, 1, 0, 0});
        pq.push({grid[0][0], 0, 2, 0, 0});

        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};

        dist[0][0][0][1]=grid[0][0];
        dist[0][0][0][2]=grid[0][0];

        while(!pq.empty()){
            int cost=pq.top()[0];
            int turns=pq.top()[1];
            int dir=pq.top()[2];
            int i=pq.top()[3];
            int j=pq.top()[4];
            pq.pop();

            // Stale entry check — a cheaper route to this exact state was
            // already found and processed.
            if(dist[i][j][turns][dir]<cost) continue;

            // KEY FIX #3: early exit. The moment we pop the destination,
            // that's guaranteed optimal (now that cost-ordering is correct) —
            // no need to keep draining the rest of the heap.
            if(i==m-1 && j==n-1) return cost;

            for(int y=0;y<4;y++){
                int nr=i+dx[y];
                int nc=j+dy[y];
                if(nr>=0 && nr<m && nc>=0 && nc<n){
                    int nturns=turns;
                    if(y!=dir){
                        nturns=turns+1;
                    }
                    if(nturns<=k){
                        int newCost = cost+grid[nr][nc];
                        if(dist[nr][nc][nturns][y]>newCost){
                            dist[nr][nc][nturns][y]=newCost;
                            pq.push({newCost, nturns, y, nr, nc});
                        }
                    }
                }
            }
        }

        // Only reached if destination was never popped (heap fully drained).
        int ans=1e9;
        for(int i=0;i<=k;i++){
            for(int j=0;j<4;j++)
                ans=min(ans,dist[m-1][n-1][i][j]);
        }
        return ans==1e9?-1:ans;
    }
};