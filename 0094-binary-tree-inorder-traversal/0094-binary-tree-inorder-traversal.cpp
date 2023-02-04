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
    // void inorder(TreeNode* root, vector<int> &v){
    //     if(root==NULL) return;
    //     inorder(root->left,v);
    //     v.push_back(root->val);
    //     inorder(root->right,v);
    // }
    // vector<int> inorderTraversal(TreeNode* root) {
    //     if(root==NULL) return {};
    //     vector<int> v;
    //     inorder(root,v);
    //     return v;
    // }
    
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        while(root!=NULL || !s.empty()){
            while(root!=NULL) {
                s.push(root);
                root=root->left;
            }
            root=s.top();
            res.push_back(root->val);
            s.pop();
            root=root->right;
        }
        return res;
    }
};