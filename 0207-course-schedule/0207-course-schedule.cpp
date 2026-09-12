class Solution {
public:
    
    bool canFinish(int V, vector<vector<int>>& edges) {
       
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);

        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        queue<int> q;

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int count = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (int nei : adj[node]) {
                indegree[nei]--;

                if (indegree[nei] == 0)
                    q.push(nei);
            }
        }

        return count == V;
    }
};