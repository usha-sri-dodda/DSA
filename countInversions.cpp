class Solution {
  public:
    int merge(vector<int> &arr, int l ,int mid, int h){
       int cnt=0;
       int i=l,j=mid+1,k=0;
       vector<int> temp(h - l + 1);
       while(i<=mid&&j<=h){
           if(arr[i]<=arr[j]){
               temp[k++]=arr[i++];
           }
           else{
               temp[k++]=arr[j++];
               cnt+=(mid-i+1);
           }
       }
        while (i <= mid) {
            temp[k++] = arr[i++];
        }
    
        // Copy remaining elements of right subarray
        while (j <= h) {
            temp[k++] = arr[j++];
        }
    
        // Copy merged elements back to original array
        for (i = l, k = 0; i <= h; ++i, ++k) {
            arr[i] = temp[k];
        }
    
        return cnt;
    }
    int mergesort(vector<int> &arr,int l, int h){
        int cnt=0;
        if(l<h) {
        int mid = l+(h-l)/2;
         cnt+=mergesort(arr,l,mid);
         cnt+=mergesort(arr,mid+1,h);
         cnt+=merge(arr,l,mid,h);
        }
        return cnt;
        
    }
    int inversionCount(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        return mergesort(arr,0,n-1);
        
    }
};
