class Solution {
  public:
    void solve(vector<vector<int>>& maze, int n, int i, int j, string path, vector<string>& res){
        if(i == n - 1 && j == n - 1 && !path.empty())    {
            res.push_back(path);
            return;
        }
        if(i < 0 || j < 0 || i >= n || j >= n || maze[i][j] == 0)   return;
        
        maze[i][j] = 0;
        
        solve(maze, n, i, j + 1, path + 'R', res);

        solve(maze, n, i, j - 1, path + 'L', res);

        solve(maze, n, i + 1, j, path + 'D', res);

        solve(maze, n, i - 1, j, path + 'U', res);
        
        maze[i][j] = 1;
        return;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n = maze.size();
        string path;
        vector<string> res;
        
        solve(maze, n, 0, 0, path, res);
        sort(res.begin(),res.end());
        return res;
    }
};
