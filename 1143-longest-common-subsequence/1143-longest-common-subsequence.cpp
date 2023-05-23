class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length(), m=text2.length();
        vector<vector<int>> v(n+1, vector<int>(m+1));
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0||j==0) v[i][j]=0;
                else if(text1[i-1]==text2[j-1])
                    v[i][j] = v[i-1][j-1] + 1;
                else
                    v[i][j] = max(v[i-1][j], v[i][j-1]);
            }
        }
        
        return v[n][m];
    }
};