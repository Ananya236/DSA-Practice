class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> vis(n,0), indegree(n,0), chainLen(n,0);

        for(int node: favorite) indegree[node]++;

        queue<int> q;
        for(int i=0;i<n;i++){
            if(!indegree[i]) q.push(i);
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            vis[curr] = 1;

            int node = favorite[curr];
            chainLen[node] = max(chainLen[node], chainLen[curr]+1);
            indegree[node]--;
            if(!indegree[node]) q.push(node);
        }

        int maxCycleLen = 0, totalChainsLen = 0;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                int currCycleLen = 0;
                int node = favorite[i]; 
                while(!vis[node]){
                    vis[node] = 1;
                    node = favorite[node];
                    currCycleLen++;
                }

                if(currCycleLen == 2){
                    totalChainsLen += 2 + chainLen[i] + chainLen[favorite[i]];
                } else {
                    maxCycleLen = max(maxCycleLen, currCycleLen);
                }
            } 
        }

        return max(maxCycleLen, totalChainsLen);
    }
};