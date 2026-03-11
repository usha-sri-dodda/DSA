class Solution {
public:
    int solve(int ind, vector<int>& coins, int amount, vector<vector<int>>& dp){
        if(amount == 0) return 1;
        if(ind == coins.size() || amount < 0) return 0;

        if(dp[ind][amount] != -1) return dp[ind][amount];

        int ans = 0;

        // take coin
        if(coins[ind] <= amount)
            ans += solve(ind, coins, amount - coins[ind], dp);

        // not take coin
        ans += solve(ind + 1, coins, amount, dp);

        return dp[ind][amount] = ans;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return solve(0, coins, amount, dp);
    }
};
