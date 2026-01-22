class Solution {
public:
    int findDays(vector<int>& weights,int capacity){
        int days=1,load=0;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]>capacity){
                load=weights[i];
                days+=1;
            }
            else load+=weights[i];
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi=INT_MIN,sum=0;
        int n=weights.size();
        for(int i=0;i<n;i++){
            if(weights[i]>maxi) maxi=weights[i];
            sum+=weights[i];
        }
        int low=maxi,high=sum,mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(findDays(weights,mid)<=days) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};
