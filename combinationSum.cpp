class Solution {
public:
    void help(vector<int>& nums,int idx,int target,vector<int>& ds,vector<vector<int>>& res){
        
        if(idx==nums.size()){
            if(target==0)   res.push_back(ds);
            return;
        }
        if(nums[idx]<=target)   { 
            ds.push_back(nums[idx]);
            help(nums,idx,target-nums[idx],ds,res);
            ds.pop_back();
        }
        help(nums,idx+1,target,ds,res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> ds;
        help(candidates,0,target,ds,res);
        return res;
    }
};
