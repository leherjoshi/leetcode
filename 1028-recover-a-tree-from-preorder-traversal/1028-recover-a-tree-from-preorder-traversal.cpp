class Solution {
public:

    int i = 0;

    TreeNode* dfs(string &s, int depth)
    {
            int d=i;

        int cnt=0;
       while(s[i]=='-'&&i<s.size()){
        cnt++;
        i++;
       }

        // 3. If depth mismatch
        //    restore index
        //    return NULL
        if(depth!=cnt){
            i=d;
            return NULL;
        }

        // 4. Read complete number
        int num=0;
            while(i<s.size()&&isdigit(s[i])){
                num=num*10+(s[i++]-'0');
            }

        // 5. Create node
        TreeNode*root= new TreeNode(num);

        // 6. node->left = dfs(...)
            root->left=dfs(s,depth+1);
        // 7. node->right = dfs(...)
            root->right=dfs(s,depth+1);
        // 8. return node
        return root;
    }

    TreeNode* recoverFromPreorder(string traversal)
    {
        return dfs(traversal,0);
    }
};