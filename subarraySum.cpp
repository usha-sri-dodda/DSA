class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixSum;
        prefixSum[0]=1;
        
        int cnt=0,sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int rem=sum-k;
            cnt+=prefixSum[rem];
            prefixSum[sum]+=1;
        }
        return cnt;
    }
};
