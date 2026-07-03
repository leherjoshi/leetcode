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
    TreeNode* func(vector<pair<int,int>> &pre,int &ind,int lvl)
    {
        if(ind==pre.size()) return NULL;
        if(lvl!=pre[ind].second) return NULL;
        TreeNode *ans=new TreeNode(pre[ind].first);
        ind++;
        ans->left=func(pre,ind,lvl+1);
        ans->right=func(pre,ind,lvl+1);
        return ans;
    }
    TreeNode* recoverFromPreorder(string s) {
        vector<pair<int,int>> pre;
        int i=0;
        int depth=0;
        int num=0;
        while(i<s.size())
        {
            depth=0;
            while(s[i]=='-')
            {
                depth++;
                i++;
            }
            num=0;
            while(i<s.size()&&s[i]!='-')
            {
                num*=10;
                num+=s[i]-'0';
                i++;
            }
            pre.push_back({num,depth});
        }
        int ind=0;
        return func(pre,ind,0);
    }
};