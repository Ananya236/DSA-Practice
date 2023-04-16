class Solution {
public:
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj){
        vis[node]=1;
        for(auto v: adj[node]){
            if(!vis[v]) dfs(v,vis,adj);
        }
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> vis(n,0);
        dfs(source,vis,adj);
        
        if(vis[destination]) return true;
        return false;
    }
};