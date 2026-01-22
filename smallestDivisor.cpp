class Solution {
public:
    int sumByD(vector<int>& arr, int d){
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=(ceil)((double)arr[i]/(douoble)d);
        }
        return sum;
    }
    int smallestDivisor(vector<int>&arr, int limit){
        int n=arr.size();
        int low=0,high=n-1,mid;
        while(low<=high){
            mid=(low+high)/2;
            if(sumByD(arr,mid)<=limit)  high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};
