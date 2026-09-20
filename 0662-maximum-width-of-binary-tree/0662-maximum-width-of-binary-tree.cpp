class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int n = q.size();
            long long first = q.front().second;
            long long last = first;

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front().first;
                long long index = q.front().second;
                q.pop();

                index -= first;

                if (i == n - 1)
                    last = index;

                if (node->left)
                    q.push({node->left, 2 * index + 1});

                if (node->right)
                    q.push({node->right, 2 * index + 2});
            }

            ans = max(ans, (int)(last + 1));
        }

        return ans;
    }
};