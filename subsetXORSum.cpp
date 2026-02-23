class Solution {
public:
   int func(vector<int>& nums,int idx, int n,vector<int>& temp,int curr){
    int sum=0;
        if(idx==n)  { return curr;}
        temp.push_back(nums[idx]);
        curr^=nums[idx];
        sum+=func(nums,idx+1,n,temp,curr);
        int t=temp[temp.size()-1];
        temp.pop_back();
        curr^=t;
        sum+=func(nums,idx+1,n,temp,curr);
        return sum;
    }
    int subsetXORSum(vector<int>& nums) {
       
        vector<int> temp;
        int n=nums.size();
        return func(nums,0,n,temp,0);
        
    }
};
