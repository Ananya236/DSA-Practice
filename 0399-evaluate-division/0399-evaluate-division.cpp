struct Dest {
    string vertex;
    double value;
};

class Solution {
public:
    
    void dfs(unordered_map<string, int> &vis,
             unordered_map<string, vector<Dest>> adj, 
             string dest, string curr, double &result, int &found)
    {
        if(curr == dest){
            found = 1;
            return;
        }
        double temp = result;
        vis[curr] = 1;
        
        for(auto list: adj[curr]){
            if(!vis[list.vertex]){
                result *= list.value;
                if(dest == list.vertex) {
                    found = 1;
                    return;
                }
                dfs(vis, adj, dest, list.vertex, result, found);
                if(found) return;
                else result = temp;
            }
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<Dest>> adj;
        set<string> vertices;
        for(int i=0; i<equations.size(); i++){
            Dest d1 = {equations[i][1], values[i]};
            adj[equations[i][0]].push_back(d1);
            
            Dest d2 = {equations[i][0], 1/values[i]};
            adj[equations[i][1]].push_back(d2);
            
            vertices.insert(equations[i][0]);
            vertices.insert(equations[i][1]);
        }
        
        vector<double> v;
        
        for(auto query: queries){
            if(vertices.find(query[0]) == vertices.end() || vertices.find(query[1]) == vertices.end()){
                v.push_back(-1.0);
                continue;
            }
            unordered_map<string, int> vis;
            double result = 1.0;
            int found = 0;
            dfs(vis, adj, query[1], query[0], result, found);
            if(found==0) result=-1.0;
            v.push_back(result);
        }
        
        return v;
    }
};