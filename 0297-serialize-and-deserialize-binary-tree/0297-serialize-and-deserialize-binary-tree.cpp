/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Preorder traversal, appending to a string with a delimiter.
    // Using '#' for NULL markers means we don't even need a separate
    // inorder traversal — one traversal is enough to rebuild the tree.
    void preorderSerialize(TreeNode* root, string &s) {
        if (!root) {
            s += "# ";
            return;
        }
        s += to_string(root->val) + " ";
        preorderSerialize(root->left, s);
        preorderSerialize(root->right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        preorderSerialize(root, s);
        return s;
    }

    // Consumes tokens one at a time from the stream, in preorder.
    TreeNode* buildFromStream(istringstream &iss) {
        string token;
        iss >> token;

        if (token == "#") return NULL;

        TreeNode* root = new TreeNode(stoi(token));
        root->left = buildFromStream(iss);
        root->right = buildFromStream(iss);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return buildFromStream(iss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));