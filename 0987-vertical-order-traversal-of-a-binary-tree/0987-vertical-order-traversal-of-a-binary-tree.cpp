/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>> mp;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int n = q.size();

            map<int, vector<int>> level;

            while (n--) {
                auto [node, col] = q.front();
                q.pop();

                level[col].push_back(node->val);

                if (node->left)
                    q.push({node->left, col - 1});

                if (node->right)
                    q.push({node->right, col + 1});
            }

            // Same row + same column → sort by value
            for (auto &[col, values] : level) {
                sort(values.begin(), values.end());

                for (int x : values)
                    mp[col].push_back(x);
            }
        }

        vector<vector<int>> ans;

        for (auto &[col, values] : mp)
            ans.push_back(values);

        return ans;
    }
};