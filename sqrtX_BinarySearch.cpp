class Solution {
public:
    int mySqrt(int x) {
        int low=1,high=x,mid,ans;
        if(x==0||x==1)  return x;
        while(low<=high){
             mid=low+(high-low)/2;
            
            if(x/mid==mid)  return mid;
            else if(mid<x/mid){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};
