class Solution {
public:
    int dp[201][10001];
    bool solve(int i, int target, vector<int>& nums){
        if(target==0 )  return true;
        if(i>=nums.size() || target < 0)  return false;
        if(dp[i][target]!=-1)   return dp[i][target];
        int take= solve(i+1,target-nums[i],nums);
        int skip= solve(i+1,target,nums);
        return dp[i][target]=take||skip;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        int sum= accumulate(nums.begin(),nums.end(),0);
        if(sum&1)    return false;
        int target = sum/2;
        return solve(0,target,nums);
    }
};
