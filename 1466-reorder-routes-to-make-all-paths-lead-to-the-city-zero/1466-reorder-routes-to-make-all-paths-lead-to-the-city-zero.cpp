class Solution {
public:
    void dfs(int source, int &edgesChanged, vector<int> &vis, vector<vector<pair<int,bool>>> &graph){
        vis[source] = 1;
        
        for(auto adj: graph[source]){
            if(!vis[adj.first]){
                if(adj.second) edgesChanged++;
                dfs(adj.first,edgesChanged,vis,graph);
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,bool>>> graph(n);
        
        for(auto conn: connections){
            graph[conn[0]].push_back({conn[1], true});
            graph[conn[1]].push_back({conn[0], false});
        }
        
        vector<int> vis(n);
        int edgesChanged=0;
        dfs(0,edgesChanged,vis,graph);
        
        return edgesChanged;
    }
};