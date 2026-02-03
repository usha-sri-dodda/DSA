class Solution {
public:
    void help(vector<int>& nums,int idx,int target,vector<int>& ds,vector<vector<int>>& res){
            if(target==0) {
                res.push_back(ds);
                return;
        }
        for(int i=idx;i<nums.size();i++)   { 
            if(i>idx && nums[i]==nums[i-1])  continue;
            if (nums[i] > target) break;
            ds.push_back(nums[i]);
            help(nums,i+1,target-nums[i],ds,res);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> ds;
        help(candidates,0,target,ds,res);
        return res;
    }
};
