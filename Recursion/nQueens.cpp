class Solution {
public:
    bool check(int row, int col, int n, vector<string>& temp){
        for(int k = 0; k < row; k++){
            if(temp[k][col] == 'Q')  return false;
        }
        for (int i = 1; i <= min(row, col); i++) {
            if (temp[row - i][col - i] == 'Q') return false;
        }
        for (int i = 1; i <= min(row, n - 1 - col); i++) {
            if (temp[row - i][col + i] == 'Q') return false;
        }
        return true;
    }
    void solve(int ind, int n, vector<vector<string>>& res, vector<string>& temp){
        if(ind == n)  {
            res.push_back(temp);
            return ;
        }
        for(int j = 0; j < n; j++){
            if(check(ind, j, n, temp)){
                    temp[ind][j] = 'Q';
                    solve(ind + 1, n, res, temp);
                    temp[ind][j] = '.';
                }

        }
        return ;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> vec(n, string(n, '.'));
        solve(0, n, res, vec);
        return res;
    }
};
