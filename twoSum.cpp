
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int,int> twoSum(vector<int> &arr,int target){
        int left=0,n=arr.size();
        int right=n-1;
        sort(arr.begin(),arr.end());
        while(left<right){
            int temp= arr[left]+arr[right];
            if(temp==target)    return {left,right};
            else if (temp>target)   right--;
            else left++;
        }
        return {-1,-1};
    }
}