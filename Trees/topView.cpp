// Top View of Binary Tree 

// Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

//        1
//     /     \
//    2       3
//   /  \    /   \
// 4    5  6   7

// Top view will be: 4 2 1 3 7
// Note: Print from leftmost node to rightmost node.

// Example :

// Input:
//       1
//    /    \
//   2      3
// Output: 2 1 3

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

vector<int> topView(struct Node *root);


int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,i,k;
        cin>>n;
        i=n;

        Node* root=NULL;
        queue <Node*> q;
        while(i>0)
        {
            int a,b;
            char c;
            cin>> a >> b >> c;
            if(!root){
                root = new Node(a);
                q.push(root);
            }
            Node* pick = q.front();
            q.pop();

            if(c == 'L'){
                pick->left = new Node(b);
                q.push( pick->left );
            }
            cin>> a >> b >> c;
            if(c == 'R'){
                pick->right = new Node(b);
                q.push( pick->right );
            }
            i-=2;
        }
//        inorder(root);
//        cout<<endl;
        vector<int> res = topView(root);
        
        for(int i=0; i<res.size(); i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}

//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// function should print the topView of the binary tree
vector<int> topView(struct Node *root)
{
    vector<int> v;
    if(root == NULL) return v;
    
    map<int,int> m;
    queue<pair<struct Node *,int>> q;
    q.push({root,0});
    
    while(!q.empty()){
        auto p = q.front();
        struct Node* n = p.first;
        int pos = p.second;
        
        if(m.find(pos)==m.end()) m[pos]=n->data; 
        q.pop();
        
        if(n->left) q.push({n->left,pos-1});
        if(n->right) q.push({n->right,pos+1});
    }
    for(auto it:m) v.push_back(it.second);
    return v;
}


