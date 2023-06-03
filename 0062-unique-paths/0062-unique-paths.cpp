class Solution {
public:
    int uniquePaths(int m, int n) {
//         *************using DP**************
        
//         vector<vector<int>> v(m,vector<int>(n));
        
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(i==0 || j==0) v[i][j]=1;
//                 else v[i][j] = v[i-1][j] + v[i][j-1];
//             }
//         }
        
//         return v[m-1][n-1];
        
        
//         *************using 1d DP***************
        
        vector<vector<int>> v(2,vector<int>(n,1));
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                v[i&1][j] = v[(i-1)&1][j] + v[i&1][j-1];
            }
        }
        
        return v[(m-1)&1][n-1];
        
        
//         *************using Math************
//         ans = (m+n-2)! / ((m-1)! (n-1)!)
        
//         long ans = 1;
//         for(int i=(m+n-2), j=1; i>=max(m,n); i--,j++){
//             ans= (ans*i)/j;
//         }
        
//         return ans;
    }
};