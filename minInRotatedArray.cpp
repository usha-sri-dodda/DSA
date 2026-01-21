class Solution {
public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
        int ans=INT_MAX,low=0,high=n-1;
        int mid;
        if(n==1)    return arr[0];
        while(low<=high){
            mid=(low+high)/2;
            if(arr[low]<arr[high]){
                ans=min(ans,arr[low]);
                break;
            }
            if(arr[low]==arr[mid]) {
                low++;
               
            }
            else if(arr[low]<=arr[mid]){
                ans=min(ans,arr[low]);
                low=mid+1;
            }
            else{
                high=mid-1;
                ans=min(ans,arr[mid]);
            }
        }
        return ans;
    }
};
