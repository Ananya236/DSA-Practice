class Solution {
public:
    bool isCycle(int source, vector<vector<int>>& graph, vector<int> &vis, vector<int> &path){
        vis[source] = 1;
        path[source] = 1;

        for(int node: graph[source]){
            if(!vis[node]){
                bool res = isCycle(node, graph, vis, path);
                if(res) return true;
            }
            else if(path[node]) return true;
        }
        
        path[source] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0), path(n, 0);
        
        for(int i=0; i<n; i++){
            if(!vis[i]) isCycle(i, graph, vis, path);
        }
        
        vector<int> res;
        
        for(int i=0; i<n; i++){
            if(!path[i]) res.push_back(i);
        }
        
        return res;
    }
};