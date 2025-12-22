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

// Method 2
class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int lastSmaller=INT_MIN,count=0,longest=0;
        for(int i=0;i<n;i++){
            if(arr[i]-1==lastSmaller){
                count++;
                lastSmaller=arr[i];
            }
            else if(arr[i]!=lastSmaller){
                count=1;
                lastSmaller=arr[i];
            }
            longest=max(longest,count);
        }
        return longest;
    }
};
