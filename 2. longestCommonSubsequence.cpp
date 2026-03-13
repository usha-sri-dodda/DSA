class Solution {
public:
    // int dp[1001][1001];
    int solve(int n, int m, string t1, string t2, vector<vector<int>>& dp){
        if(n < 0 || m < 0)  return 0;
        if(dp[n][m]!= -1)   return dp[n][m];
        int ans = 0;
        if(t1[n] == t2[m])  ans = 1 + solve(n-1, m-1, t1, t2, dp);
        else if(t1[n] != t2[m]) ans = max(solve(n, m-1, t1, t2, dp), solve(n-1, m, t1, t2, dp));
        return dp[n][m] = ans ;
    }
    int longestCommonSubsequence(string t1, string t2) {
        int n = t1.size();
        int m = t2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        // memset(dp, -1, sizeof(dp));
        return solve(n - 1, m - 1, t1, t2, dp) ;
    }
};
