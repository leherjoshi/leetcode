class Solution {
    
public:

    vector<int> parent, size;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        parent[b] = a;
        size[a] += size[b];
    }

    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();

        parent.resize(n * n);
        size.assign(n * n, 1);

        for (int i = 0; i < n * n; i++) {
            parent[i] = i;
        }

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        // Step 1: Union all neighbouring 1s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {

                    int node = i * n + j;

                    for (int d = 0; d < 4; d++) {

                        int nr = i + dx[d];
                        int nc = j + dy[d];

                        if (nr >= 0 && nc >= 0 &&
                            nr < n && nc < n &&
                            grid[nr][nc] == 1) {

                            int next = nr * n + nc;

                            unite(node, next);
                        }
                    }
                }
            }
        }

        // Find current largest island
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    ans = max(ans, size[find(i * n + j)]);
                }
            }
        }

        // Step 2: Try converting every 0 into 1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 0) {

                    int cnt = 1;

                    // Store roots so same island isn't counted twice
                    vector<int> roots;

                    for (int d = 0; d < 4; d++) {

                        int nr = i + dx[d];
                        int nc = j + dy[d];

                        if (nr >= 0 && nc >= 0 &&
                            nr < n && nc < n &&
                            grid[nr][nc] == 1) {

                            int root = find(nr * n + nc);

                           

                        if (std::find(roots.begin(), roots.end(), root) == roots.end()) {
                            roots.push_back(root);
                            cnt += size[root];
                        }
                        }
                    }

                    ans = max(ans, cnt);
                }
            }
        }

        return ans == 0 ? 1 : ans;
    }
};