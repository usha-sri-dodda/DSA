class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int right=0,ans=0,count=0;
        for(right=0;right<nums.size();right++){
            if(nums[right]==1)  count++;
            else    count=0;

            ans=max(ans,count);
        }
        return ans;
    }
};
