class Solution {
public:
    int dp[101];
    int solve(vector<int>& nums, int index, int n){
        if(index >= n)  return 0;
        if(dp[index]!=-1) return dp[index];
        int take = nums[index] + solve(nums, index+2, n);
        int nottake = solve(nums, index+1, n);
        return dp[index] = max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, n);
    }
};
