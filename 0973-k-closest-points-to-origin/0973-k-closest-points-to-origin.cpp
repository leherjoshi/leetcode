class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int,int>>> pq;
        vector<vector<int>> closed;

        for(auto p : points) {
            int x = p[0];
            int y = p[1];

            int dis = x*x + y*y;

            pq.push({dis, {x, y}});

            if(pq.size() > k)
                pq.pop();
        }

        while(!pq.empty()) {
            auto [d, p] = pq.top();
            auto [x, y] = p;

            closed.push_back({x, y});

            pq.pop();
        }

        return closed;
    }
};