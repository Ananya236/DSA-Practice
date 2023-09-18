class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> maxh;
        int m=mat.size(), n=mat[0].size();
        
        for(int i=0;i<m;i++){
            int  soldiers = 0;
            for(int j=0;j<n;j++){
                if(mat[i][j]) soldiers++;
            }
            
            maxh.push({soldiers, i});
            if(maxh.size()>k) maxh.pop();
        }
        
        vector<int> res(k);
        while(maxh.size()){
            res[k-1] = maxh.top().second;
            maxh.pop();
            k--;
        }
        
        return res;
    }
};