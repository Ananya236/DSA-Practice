class Solution {
public:
//     int findJudge(int n, vector<vector<int>>& trust) {
//         vector<vector<int>> adj(n+1);
        
//         for(int i=0;i<trust.size();i++){
//             adj[trust[i][0]].push_back(trust[i][1]);
//         }
        
//         vector<int> indegree(n+1,0);
//         for(int i=1;i<=n;i++){
//             for(auto j: adj[i]){
//                 indegree[j]++;
//             }
//         }
        
//         for(int i=1;i<=n;i++){
//             if(indegree[i]==n-1 && adj[i].size()==0) return i;
//         }
        
//         return -1;
//     }
    
    
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n+1,0),outdegree(n+1,0);
        
        for(int i=0;i<trust.size();i++){
            outdegree[trust[i][0]]++;
            indegree[trust[i][1]]++;
        }
        
        for(int i=1;i<=n;i++){
            if(indegree[i]==n-1 && outdegree[i]==0) return i;
        }
        
        return -1;
    }
};