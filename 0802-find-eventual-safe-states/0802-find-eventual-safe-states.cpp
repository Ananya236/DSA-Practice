// class Solution {
// public:
//     bool foundCycle(vector<vector<int>>& graph, vector<int> &vis, int curr, vector<int> &res){
//         vis[curr] = 1;
//         for(int i: graph[curr]){
//             if(vis[i]==1 || (!vis[i] && !foundCycle(graph, vis, i, res))) return false;
//         }
//         vis[curr]=2;
//         res.push_back(curr);
//         return true;
//     }
    
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<int> vis(n,0);
//         vector<int> res;
        
//         for(int i=0;i<n;i++)
//             if(!vis[i])
//                 foundCycle(graph, vis, i, res);
        
//         sort(res.begin(), res.end());
        
//         return res;
//     }
// };

// class Solution {
// public:
//     bool dfs(vector<vector<int>>& graph, vector<int>& visited, vector<int>& res, int curr) {
//         visited[curr] = 1;
        
//         for (int next : graph[curr]) {
//             if (visited[next] == 1 || (!visited[next] && !dfs(graph, visited, res, next))) {
//                 return false;
//             }
//         }
        
//         visited[curr] = 2;
//         res.push_back(curr);
        
//         return true;
//     }
    
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<int> visited(n, 0);
//         vector<int> res;
        
//         for (int i = 0; i < n; i++) {
//             if (!visited[i]) {
//                 dfs(graph, visited, res, i);
//             }
//         }
        
//         sort(res.begin(), res.end());
//         return res;
//     }
// };


class Solution {
public:
    bool foundCycle(vector<vector<int>>& graph, vector<int> &vis, int curr, vector<int> &res){
        vis[curr] = 1;
        bool isCycle = false;
        for(auto i: graph[curr]){
            if(vis[i] == 0) {
                isCycle = foundCycle(graph, vis, i, res);
            } else if(vis[i] == 1) {
                isCycle = true;
            }
            if(isCycle) return true;
        }
        vis[curr]=2;
        res.push_back(curr);
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> res;
        
        for(int i=0;i<n;i++)
            if(vis[i]==0)
                foundCycle(graph, vis, i, res);
        
        sort(res.begin(), res.end());
        
        return res;
    }
};