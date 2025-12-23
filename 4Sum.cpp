class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int j=0,k=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            for(int l=i+1;l<n;l++){
                if(l!=i+1&&nums[l]==nums[l-1])  continue;
                j=l+1;
                k=n-1;
                while(j<k){
                    long long sum=nums[i];
                    sum+=nums[l];
                    sum+=nums[j];
                    sum+=nums[k];
                    if(sum==target){
                        vector<int> temp={nums[i],nums[l],nums[j],nums[k]};
                        res.push_back(temp);
                        j++;
                        k--;
                        while(j<k&&nums[j]==nums[j-1])   j++;
                        while(j<k&&nums[k]==nums[k+1])   k--;
                    }
                    else if(sum>target)  k--;
                    else    j++;
                }
            }
        }
        return res;
    }
};
