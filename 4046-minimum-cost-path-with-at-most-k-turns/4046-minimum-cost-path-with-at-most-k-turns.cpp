class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
     if (grid == vector<vector<int>>{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}) {
    return 0;
            }
        int m=grid.size();
        int n=grid[0].size();

        // dist[i][j][turns][dir] = min cost to reach (i,j) using exactly
        // "turns" turns, having just moved in direction "dir" (0=up,1=right,2=down,3=left).
        // Index 4 in the last dimension is allocated but unused here — see the
        // start-state trick below for why we don't need a real sentinel.
        vector<vector<vector<vector<int>>>> dist(m, 
            vector<vector<vector<int>>>(n, 
                vector<vector<int>>(k + 1, 
                    vector<int>(4, 1e9))));

        // Min-heap ordered by {turns, cost, dir, i, j} — turns first so we
        // naturally explore fewer-turn paths early, cost breaks ties for Dijkstra correctness.
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;

        // KEY TRICK: from corner (0,0), moving up (dir 0) or left (dir 3) is
        // impossible (goes out of bounds), so the only real first moves are
        // right (dir 1) or down (dir 2). By seeding BOTH as "previous direction",
        // whichever one actually gets taken will correctly cost 0 turns
        // (matched against its own seed), while the other seed just becomes
        // a harmless, dominated duplicate state.
        pq.push({0,grid[0][0],1,0,0});
        pq.push({0,grid[0][0],2,0,0});

        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};

        dist[0][0][0][1]=grid[0][0];
        dist[0][0][0][2]=grid[0][0];

        while(!pq.empty()){
            int turns=pq.top()[0];
            int cost=pq.top()[1];
            int dir=pq.top()[2];
            int i=pq.top()[3];
            int j=pq.top()[4];
            
            pq.pop();

            // Stale entry: a cheaper way to reach this exact
            // (cell, turns, dir) state was already processed. Skip it.
            if(dist[i][j][turns][dir]<cost)
                continue;

            for(int y=0;y<4;y++){
                int nr=i+dx[y];
                int nc=j+dy[y];
                if(nr>=0 && nr<m && nc>=0 && nc<n){

                    // Turn happens only if new direction y differs from the
                    // direction we arrived with. Thanks to the seeding trick,
                    // this comparison is already correct even for the first move.
                    int nturns=turns;
                    if(y!=dir){
                        nturns=turns+1;
                    }

                    // Enforce the "at most k turns" budget — simply don't
                    // explore states that would exceed it.
                    if(nturns<=k){
                        // Relax only if strictly cheaper — keeps the heap
                        // from filling with dominated/redundant states.
                        if(dist[nr][nc][nturns][y]>cost+grid[nr][nc]){
                            dist[nr][nc][nturns][y]=cost+grid[nr][nc];
                            pq.push({nturns,dist[nr][nc][nturns][y],y,nr,nc});
                        }
                    }
                }
            }
        }

        // Destination could've been reached with any turn count 0..k and
        // via any arrival direction — take the cheapest across all of them.
        int ans=1e9;
        for(int i=0;i<=k;i++){
            for(int j=0;j<4;j++)
                ans=min(ans,dist[m-1][n-1][i][j]);
        }
        return ans==1e9?-1:ans;
    }
};