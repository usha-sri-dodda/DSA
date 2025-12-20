class Solution {
public:
    int robSum(vector<int>& nums){
        int prev=nums[0],prev2=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1) take+=prev2;
            int notTake=0+prev;
            int curr=max(take,notTake);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        vector<int> temp1,temp2;
        int n=nums.size();
        if(n==1)    return nums[0];
        for(int i=0;i<n-1;i++)  temp1.push_back(nums[i]);
        for(int i=1;i<n;i++)  temp2.push_back(nums[i]);
        return max(robSum(temp1),robSum(temp2));
    }

};
