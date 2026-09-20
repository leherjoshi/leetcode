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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;

        vector<vector<int>>res;

        q.push(root);

        while(!q.empty()){
            int s=q.size();
            vector<int>ans;
            for(int i=0;i<s;i++){
                TreeNode*nw=q.front();
                q.pop();

                if(nw)
                {
                ans.push_back(nw->val);

                if(nw->left)q.push(nw->left);
                if(nw->right)q.push(nw->right);
                }
            }
            if(!ans.empty())res.push_back(ans);
        }
        return res;


    }
};