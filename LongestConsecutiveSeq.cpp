class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin() , nums.end());
        int number , count = 0 , ans = 0;
        for(int nums : s){
            if(s.find(nums - 1) == s.end()){
                number = nums;
                count = 0;
            while(s.find(number) != s.end()){
                number += 1;
                count++;
            }
            }
            if(count > ans){
                ans = count;
            }
            count = 0;
        }
        return ans;
    }
};
