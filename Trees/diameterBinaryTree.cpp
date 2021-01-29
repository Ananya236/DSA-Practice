// #GFG
// #Diameter of A Binary Tree

// Given a Binary Tree, find diameter of it.
// The diameter of a tree is the number of nodes on the longest path between two end nodes in the tree. 

// Example 1:

// Input:
//        1
//      /  \
//     2    3
// Output: 3

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}
/* Function to get diameter of a binary tree */
int diameter(struct Node* tree);

int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        cout << diameter(root) << endl;
    }
    return 0;
}

/* Computes the left and rignt path of given node. */ 
int findDiameter(Node* root,int &res){
    if(root==NULL)
    return 0;
    int l=findDiameter(root->left,res);
    int r=findDiameter(root->right,res);
    int longest_path = 1+max(l,r);
    int dia = 1+l+r;  //diameter for that node
    res=max(res,dia);
    return longest_path;   // return max path from leaf node to that node
}

/* Computes the diameter of binary tree with given root.  */
int diameter(Node* root) {
    int res=INT_MIN;
    findDiameter(root,res);
    return res;
}
