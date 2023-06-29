class Solution {
public:
    bool dfs(vector<vector<int>> &adj, vector<int> &vis, int curr){
        if(vis[curr]==-1) 
            vis[curr] = 1;
        
        for(int node : adj[curr]){
            if(vis[node]==vis[curr]) return true;
            if(vis[node]==-1){
                vis[node] = 1-vis[curr];
                if(dfs(adj,vis,node)) return true;
            }
        }
        return false;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        
        for(auto edge: dislikes){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> vis(n+1,-1);
        
        for(int i=1;i<=n;i++){
            if(vis[i]==-1 && dfs(adj, vis, i)) return false;
        }
        
        return true;
    }
};