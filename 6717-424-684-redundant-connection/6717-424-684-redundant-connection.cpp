class Solution {
public:
    vector<int> isCycle(int source, int parent, int pathCnt, vector<vector<int>>& graph, vector<int> &vis, vector<int> &path){
        vis[source]=1;
        path[source]=++pathCnt;

        for(int node: graph[source]){
            if(!vis[node]){
                vector<int> res = isCycle(node, source, pathCnt, graph, vis, path);
                if(res.size()) return res;
            } else if(node != parent) return {path[node], path[source]};
        }

        path[source]=0;
        return {};
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n+1);

        for(vector<int> edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(n+1,0), path(n+1,0);

        vector<int> endpoints = isCycle(1, 0, 0, graph, vis, path);

        int st = endpoints[0], ed = endpoints[1];

        for(int i=n-1; i>=0; i--){
            if(path[edges[i][0]]>=st && path[edges[i][1]] && path[edges[i][1]]<=ed)
                return {edges[i][0], edges[i][1]};
        }

        return {};
    }
};