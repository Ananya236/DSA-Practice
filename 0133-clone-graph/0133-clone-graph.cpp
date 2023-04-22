/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node, unordered_map<Node*, Node*> &um){
        Node *copyNode = new Node(node->val);
        um[node] = copyNode;
        
        for(auto i: node->neighbors){
            if(um.find(i) != um.end()){
                copyNode->neighbors.push_back(um[i]);
            } else{
                dfs(i,um);
                copyNode->neighbors.push_back(um[i]);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> um;
        if(node==NULL) return node;
        dfs(node, um);
        return um[node];
    }
};