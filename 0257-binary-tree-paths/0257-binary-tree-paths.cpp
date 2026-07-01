class Solution {
public:
    void dfs(TreeNode* root, vector<string>& vs, string s) {
        if (root == nullptr) return;

        if (root->left == nullptr && root->right == nullptr) {
            vs.push_back(s);
            return;
        }

        if (root->left)
            dfs(root->left, vs, s + "->" + to_string(root->left->val));

        if (root->right)
            dfs(root->right, vs, s + "->" + to_string(root->right->val));
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> vs;

        if (root == nullptr) return vs;

        dfs(root, vs, to_string(root->val));
        return vs;
    }
};