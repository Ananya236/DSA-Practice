// Right View Of Binary Tree

// Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

// Right view of following tree is 1 3 7 8.

//           1
//        /     \
//      2        3
//    /   \      /    \
//   4     5   6    7
//     \
//      8

// Example :

// Input:
//        1
//     /    \
//    3      2
// Output: 1 2

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

vector<int> rightView(struct Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);

        vector<int> vec = rightView(root);
        for(int x : vec){
            cout<<x<<" ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
vector<int> rightView(Node *root)
{
    vector<int> v;
    if (root == NULL)  return v;
    queue<Node*> q;
    q.push(root);
    int cnt=0;
    while (q.empty() == false)
    {
        cnt=q.size();
        while(cnt--){
            Node *root = q.front();
            q.pop();
            if(cnt==0){
                v.push_back(root->data);
            }
            if (root->left != NULL)
                q.push(root->left);
            if(root->right != NULL)
                q.push(root->right);
        }
    }
    return v;
}

