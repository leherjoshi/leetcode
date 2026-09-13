class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);

        for(auto f:flights){
            adj[f[0]].push_back({f[1],f[2]});
        }

        priority_queue<pair<int,pair<int,int>>,
                    vector<pair<int,pair<int,int>>>,
                    greater<>
                    >pq;
        // priority_queue<pair<int,pair<int,int>>, 
        //             vector<pair<int,pair<int,int>>>,
        //             greater<pair<int,pair<int,int>>
        //             >> pq;

        
        pq.push({0,{src,0}});
        vector<vector<int>>dist(n,vector<int>(k+2,INT_MAX));
        while(!pq.empty()){
            auto [cost,cell]=pq.top();
            pq.pop();

            int node=cell.first;
            int stop=cell.second;
            if(node==dst)return cost;
            if(stop>k)continue;
            for(auto [nei,cost2]:adj[node]){
                if(cost+cost2<dist[nei][stop+1]){
                    dist[nei][stop+1]=cost+cost2; 
                    pq.push({cost+cost2,{nei,stop+1}});
                }
            }
        }
        return -1;
    }
};