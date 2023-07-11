class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int wi, vector<vector<int>> &vis){
        if(wi == word.size()) return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || vis[i][j]) return false;
        vis[i][j]=1;
        bool ans = false;
        if(board[i][j]==word[wi]) {
            ans = dfs(board, word, i, j+1, wi+1, vis) || 
                   dfs(board, word, i, j-1, wi+1, vis) || 
                   dfs(board, word, i+1, j, wi+1, vis) || 
                   dfs(board, word, i-1, j, wi+1, vis) ;
        }
        vis[i][j]=0;
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(board, word, i, j, 0, vis)) return true;
            }
        }
        
        return false;
    }
};