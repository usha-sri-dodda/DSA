class Solution {
public:
    void merge(vector<int>& a, int low, int mid,int high) {
        vector<int> temp;
        int left=low,right=mid+1;
        
        while(left<=mid&&right<=high){
            if(a[left]<a[right]){
                temp.push_back(a[left]);
                left++;
            }
            else{
                temp.push_back(a[right]);
                
                right++;
            }
        }
        while(left<=mid)    {
            temp.push_back(a[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(a[right]);
            right++;
        }
        for(int i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
    }
    void mergerSort(vector<int>& a, int low, int high){
        if(low>=high)   return ;
        int mid=(low+high)/2;
        mergerSort(a,low,mid);
        mergeSort(a,mid=1,high);
        merge(a,low,mid,high);
    }
    void performMerge(vector<int>& a){
        int  n=a.size();
        mergeSort(a,0,n-1);
    }
};


