class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*, TreeNode*> parent;

        // Store parent of every node
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }

            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        // BFS from target
        unordered_map<TreeNode*, bool> visited;

        q.push(target);
        visited[target] = true;

        int distance = 0;

        while (!q.empty() && distance < k) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left && !visited[node->left]) {
                    visited[node->left] = true;
                    q.push(node->left);
                }

                if (node->right && !visited[node->right]) {
                    visited[node->right] = true;
                    q.push(node->right);
                }

                if (parent[node] && !visited[parent[node]]) {
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                }
            }

            distance++;
        }

        vector<int> ans;

        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};