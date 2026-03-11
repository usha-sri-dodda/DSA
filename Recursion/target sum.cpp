class Solution {
public:
    int dp[21][2001];   // to handle -1000 to +1000

    int solve(int ind, int n, vector<int>& nums, int sum, int target){
        if(ind == n){
            return sum == target ? 1 : 0;
        }

        if(dp[ind][sum + 1000] != -1) 
            return dp[ind][sum + 1000];

        int count = 0;

        count += solve(ind + 1, n, nums, sum + nums[ind], target);
        count += solve(ind + 1, n, nums, sum - nums[ind], target);

        return dp[ind][sum + 1000] = count;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, n, nums, 0, target);
    }
};
