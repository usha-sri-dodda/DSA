class Solution {
public:
    bool check(vector<vector<char>>& board, int  i, int j, int val){
        for(int k = 0; k < 9; k++){
            if(board[i][k] - '0' == val || board[k][j] - '0' == val)    return false;
        }

        int srow = (i / 3) * 3, scol = (j / 3) * 3;

        for(int row = srow; row < srow + 3; row++){
            for(int col = scol; col < scol + 3; col++){
                if(board[row][col] - '0' == val)  return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board, int i, int j){
        if(i == 9)    return true;
        else if(j == 9) return solve(board, i + 1, 0);
        if(board[i][j] != '.')  return solve(board, i, j + 1);
        if(board[i][j] == '.'){
            for(int val = 1; val <= 9; val++){
                if(check(board, i, j, val)){
                    board[i][j] = '0' + val;
                    if(solve(board, i, j + 1))
                        return true;
                    board[i][j] = '.';
                }
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};
