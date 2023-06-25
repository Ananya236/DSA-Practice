struct WtVertex{
    int vertex;
    int weight;
};

class Solution {
public:
    int getMinV(vector<int> wt, vector<int> vis){
        int minWt = INT_MAX, minV=0;
        for(int j=1; j<wt.size(); j++) 
            if(!vis[j-1] && wt[j]<minWt) {
                minV=j;
                minWt=wt[j];
            }
        return minV;
    }
    
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<WtVertex>> adj(n+1);
        
        for(int i=0;i<times.size();i++){
            WtVertex w = {times[i][1], times[i][2]};
            adj[times[i][0]].push_back(w);
        }
        
        vector<int> wt(n+1, INT_MAX);
        vector<int> vis(n, 0);
        
        wt[k] = 0;
        
        for(int i=0; i<n; i++){
            int minV = getMinV(wt, vis);
            cout<<minV<<"\n";
            if(!minV) return -1;
            vis[minV-1] = 1;
            
            for(auto j: adj[minV]){
                if(!vis[j.vertex-1]){
                    wt[j.vertex] = min(j.weight+wt[minV], wt[j.vertex]);
                }
            }
        }
        
        for(auto i: vis){
            if(i==0) return -1;
        }
        
        int result = 0;
        for(int i=1; i<n+1; i++){
            if(wt[i]>result) result = wt[i];
        }
        
        return result;
    }
};