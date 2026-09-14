class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        int pu = find(x);
        int pv = find(y);

        if (pu == pv)
            return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();

        DSU ds(n * n);

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        bool hasZero = false;

        // Step 1: Union adjacent 1s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 0) {
                    hasZero = true;
                    continue;
                }

                int node = i * n + j;

                for (int d = 0; d < 4; d++) {

                    int nr = i + dx[d];
                    int nc = j + dy[d];

                    if (nr >= 0 && nc >= 0 &&
                        nr < n && nc < n &&
                        grid[nr][nc] == 1) {

                        int adjNode = nr * n + nc;

                        ds.unite(node, adjNode);
                    }
                }
            }
        }

        // All 1s
        if (!hasZero)
            return n * n;

        int ans = 1;

        // Step 2: Flip every 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1)
                    continue;

                set<int> components;

                for (int d = 0; d < 4; d++) {

                    int nr = i + dx[d];
                    int nc = j + dy[d];

                    if (nr >= 0 && nc >= 0 &&
                        nr < n && nc < n &&
                        grid[nr][nc] == 1) {

                        components.insert(ds.find(nr * n + nc));
                    }
                }

                int total = 1;

                for (auto root : components) {
                    total += ds.size[root];
                }

                ans = max(ans, total);
            }
        }

        // All 0s is automatically handled:
        // ans remains 1
        return ans;
    }
};