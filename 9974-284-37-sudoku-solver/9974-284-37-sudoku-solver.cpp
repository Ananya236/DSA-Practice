class Solution {
    vector<vector<bool>> rows, cols, squares;

    bool solve(vector<vector<char>>& board, int i, int j) {
        if(i==9) return true;
        if(j==9) return solve(board, i+1, 0);
        if(board[i][j]!='.') return solve(board, i, j+1);

        for(int k=1; k<=9; k++){
            int squareIndex = (i / 3) * 3 + j / 3;
            if(rows[i][k] || cols[j][k] || squares[squareIndex][k]) continue;

            board[i][j] = k+'0';
            rows[i][k] = cols[j][k] = squares[squareIndex][k] = true;

            bool res = solve(board, i, j+1);
            if(res) return res;

            board[i][j] = '.';
            rows[i][k] = cols[j][k] = squares[squareIndex][k] = false;
        }

        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        rows.resize(9, vector<bool>(10, false));
        cols.resize(9, vector<bool>(10, false));
        squares.resize(9, vector<bool>(10, false));

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){\
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    rows[i][num] = cols[j][num] = squares[(i / 3) * 3 + j / 3][num] = true;
                }
            }
        }

        solve(board,0,0);
    }
};