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
//     void preorder(TreeNode* node, vector<int> &v){
//         if(node==NULL) return;
//         v.push_back(node->val);
//         preorder(node->left, v);
//         preorder(node->right, v);
//     }
    
//     vector<int> preorderTraversal(TreeNode* root) {
//         if(root==NULL) return {};
//         vector<int> v;
//         preorder(root, v);
//         return v;
//     }
    
       vector<int> preorderTraversal(TreeNode* root) {
           if(root==NULL) return {};
           stack<TreeNode*> s;
           vector<int> v;
           s.push(root);
           while(!s.empty()){
               root=s.top();
               s.pop();
               v.push_back(root->val);
               if(root->right) s.push(root->right);
               if(root->left) s.push(root->left);
           }
           return v;
       }
};