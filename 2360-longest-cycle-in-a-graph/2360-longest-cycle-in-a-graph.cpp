class Solution {
public:
    void dfs(int source, int &pathCount, int &longestCycleLen, vector<int> &edges, vector<int> &vis, vector<int> &path){
        vis[source] = 1;
        path[source] = ++pathCount;
        
        int node = edges[source];
        if(node!=-1)
        {
            if(!vis[node]){
                dfs(node, pathCount, longestCycleLen, edges, vis, path);
            }
            else if(path[node]){
                longestCycleLen = max(longestCycleLen, pathCount-path[node]+1);
            }
        }
        path[source]=0;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> vis(n,0);
        vector<int> path(n,0);
        
        int pathCount = 0, longestCycleLen = -1;
        
        for(int i=0; i<n; i++){
            if(!vis[i])
                dfs(i, pathCount, longestCycleLen, edges, vis, path);
        }
        return longestCycleLen;
    }
};