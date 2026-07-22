class Solution {
public:
    int postIndex;   // CHANGED: global index to track current root in postorder

    TreeNode* build(int i, int j, vector<int>& inorder, vector<int>& postorder) {

        // CHANGED: correct base case
        if (i > j) return nullptr;

        // CHANGED: current root comes from postorder[postIndex]
        TreeNode* root = new TreeNode(postorder[postIndex--]);

        // CHANGED: find root in inorder
        int l;
        for (l = i; l <= j; l++) {
            if (inorder[l] == root->val)
                break;
        }

        // CHANGED: build RIGHT first, then LEFT
        root->right = build(l + 1, j, inorder, postorder);
        root->left = build(i, l - 1, inorder, postorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        // CHANGED: initialize postorder index
        postIndex = postorder.size() - 1;

        // CHANGED: last index is size()-1
        return build(0, inorder.size() - 1, inorder, postorder);
    }
};