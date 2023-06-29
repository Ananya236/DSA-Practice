class Solution { 
public:
    int find(vector<int> &parents, int curr){
        if(parents[curr]==curr) return curr;
        return parents[curr] = find(parents,parents[curr]);
    }
    
    void merge(vector<int> &parents, int stone1, int stone2){
        int parent1 = find(parents, stone1);
        int parent2 = find(parents, stone2);
        parents[parent1] = parent2;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> parents(n, -1);
        
        for(int i=0;i<n;i++){
            parents[i] = i;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    merge(parents,i,j);
                }
            }
        }
        
        int result = 0;
        for(int i=0; i<n; i++) if(parents[i]==i) result++;
        
        return n-result;
    }
};