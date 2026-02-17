class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        int currMax = 0,currMin=0,total=0;
        int resMax = arr[0], resMin=arr[0];
        for(int i=0;i<n;i++){
            currMax=max(currMax+arr[i],arr[i]);
            resMax=max(resMax,currMax);
            
            currMin=min(currMin+arr[i],arr[i]);
            resMin=min(resMin,currMin);
            total+=arr[i];
        }
        int normal=resMax;
        int circular=total-resMin;
        if(resMin==total)   return normal;
        return max(circular,normal);
    }
};
