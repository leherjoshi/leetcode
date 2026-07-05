class Solution {
public:
    int n;

    bool find(int limit,
              unordered_map<int, vector<pair<int,int>>> &adj,
              vector<bool> &online,
              long long k)
    {
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        vector<long long> dist(n, LLONG_MAX);

        dist[0] = 0;
        pq.push({0,0});

        while(!pq.empty())
        {
            auto [currcost,node] = pq.top();
            pq.pop();

            if(currcost > dist[node])
                continue;

            for(auto &nxt : adj[node])
            {
                auto [v,cost] = nxt;

                if(v != n-1 && !online[v])
                    continue;

                // Use limit here according to the problem.
                // Example:
                if(cost < limit) continue;

                long long nwcost = currcost + cost;

                if(nwcost < dist[v])
                {
                    dist[v] = nwcost;
                    pq.push({nwcost,v});
                }
            }
        }

        return dist[n-1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         long long k)
    {
        n = online.size();

        unordered_map<int, vector<pair<int,int>>> adj;

        int low = 0;
        int high = 0;

        for(auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            int c = e[2];

            adj[u].push_back({v,c});
            high = max(high, c);
        }

        int ans = -1;

        while(low <= high)
        {
            int mid = low + (high-low)/2;

            if(find(mid, adj, online, k))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};