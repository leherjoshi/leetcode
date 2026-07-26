class Solution {
public:
    int ans = 0;

    struct Node {
        bool isBST;
        int mn, mx, sum;
    };

    Node dfs(TreeNode* root) {
        if (!root)
            return {true, INT_MAX, INT_MIN, 0};

        Node L = dfs(root->left);
        Node R = dfs(root->right);

        if (L.isBST && R.isBST &&
            root->val > L.mx &&
            root->val < R.mn) {

            int s = L.sum + R.sum + root->val;
            ans = max(ans, s);

            return {
                true,
               min(root->val, L.mn),
                 max(root->val, R.mx),
        
                s
            };
        }

        return {false, INT_MIN, INT_MAX, 0};
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};