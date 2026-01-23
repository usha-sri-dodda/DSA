class Solution {
public:
    bool canPlace(vector<int>& nums, int pos,int cowslimit) {
        int cows=1,last=arr[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(arr[i]-last>=pos){
                cows+=1;
                last=arr[i];
            }
            
        }
        if(cows>=cowslimit) return true;
        else false;
    }
    int findMaxDist(vector<int>& pos,int cows){
        int n=nums.size();
        int low=0,high=n-1;
        int mid,ans;
        while(low<=high){
            mid=(low+high)/2;
            if(canPlace(pos,mid,cows)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};
