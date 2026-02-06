class Solution {
public: void backtrack(vector<int>& nums,int start , vector<vector<int>>& res){
        if(start==nums.size()){
            res.push_back(nums);
            return ;
        }
        unordered_set<int> used;

        for (int i = start; i < nums.size(); i++) {

            if (used.count(nums[i])) continue;   // avoid duplicate at this position
            used.insert(nums[i]);
            swap(nums[start],nums[i]);
            backtrack(nums,start+1,res);
            swap(nums[start],nums[i]);
        }
    }
    void swap(int& a,int& b){
        int temp=a;
        a=b;
        b=temp;
    } 
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        backtrack(nums,0,res);
        return res;
    }
};
