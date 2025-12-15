class Solution{
    public:
        int sqrt(int n){
            int l=1,h=n,res=1;
            while(l<=h){
                int mid=l+(h-l)/2;
                if(mid*mid<=n) {
                    res=mid;
                    l=mid+1;
                }
                else{
                    h=mid-1;
                }
            }
            return res;

            //Time Complexity -- O(log(n))  Space Complexity -- O(1)
        }
}
