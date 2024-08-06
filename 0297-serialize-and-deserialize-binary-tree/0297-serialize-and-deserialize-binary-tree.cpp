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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root)
            return to_string(root->val) + ' ' + serialize(root->left) + serialize(root->right);
        return "NULL ";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream inp(data);
        return deserialize(inp);
    }
    
    TreeNode* deserialize(istringstream &inp){
        string s;
        inp >> s;
        
        if(s=="NULL") return NULL;
        TreeNode *root = new TreeNode(stoi(s));
        root->left = deserialize(inp);
        root->right = deserialize(inp);
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));