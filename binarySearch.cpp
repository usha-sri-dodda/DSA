// Binary Search
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int n=nums.size();
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target)   return mid;
            else if (nums[mid]<target)  low=mid+1;
            else high=mid-1;

        }
        return -1;
    }
};

// LowerBound
class Solution {
public:
    int lowerBound(vector<int>& nums, int target) {
        int low=0;
        int n=nums.size();
        int high=n-1;
        int ans=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>=target)   {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};

// Upper Bound
class Solution {
public:
    int upperBound(vector<int>& nums, int target) {
        int low=0;
        int n=nums.size();
        int high=n-1;
        int ans=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>target)   {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};
