class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>v (numRows);
        for(int i=0;i<numRows;i++){
            v[i]={1};
            for(int j=1;j<=i;j++){
                if(j==i) v[i].push_back(1);
                else v[i].push_back(v[i-1][j-1]+v[i-1][j]);
            }
        }
        return v;
    }
};