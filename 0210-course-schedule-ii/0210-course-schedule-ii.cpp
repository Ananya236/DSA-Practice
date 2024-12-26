class Solution {
public:
    bool dfs(int source, vector<vector<int>> &graph, vector<int> &vis, stack<int> &s, vector<int> &path){
        vis[source] = 1;
        path[source] = 1;
        for(int node: graph[source]){
            if(!vis[node]) {
                bool res = dfs(node, graph, vis, s, path);
                if(res) return true;
            }
            else if(path[node]) return true;
        }
        s.push(source);
        path[source] = 0;
        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        
        for(vector<int> pq:  prerequisites){
            graph[pq[1]].push_back(pq[0]);
        }
        
        vector<int> vis(numCourses, 0);
        vector<int> path(numCourses, 0);
        stack<int> s;
        
        for(int i=0; i<numCourses; i++){
            if(!vis[i]) {
                bool res = dfs(i, graph, vis, s, path);
                if(res) return {};
            }
        }
        
        vector<int> res;
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        
        return res;
    }
};