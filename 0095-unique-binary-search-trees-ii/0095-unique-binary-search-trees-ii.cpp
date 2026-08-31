class Solution {
public:

    vector<TreeNode*> solve(int start, int end) {

        vector<TreeNode*> ans;

        if(start > end) {
            ans.push_back(NULL);
            return ans;
        }

        for(int root = start; root <= end; root++) {

            vector<TreeNode*> left = solve(start, root - 1);
            vector<TreeNode*> right = solve(root + 1, end);

            for(int i = 0; i < left.size(); i++) {
                for(int j = 0; j < right.size(); j++) {

                    TreeNode* node = new TreeNode(root);

                    node->left = left[i];
                    node->right = right[j];

                    ans.push_back(node);
                }
            }
        }

        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};