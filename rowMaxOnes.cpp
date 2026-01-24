class Solution {
public:
    int lowerBound(vector<int>arr, int n, int x){
        int low=0, high=n-1, ans=n;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]>=x){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int>ans(2,0);
        int n=mat.size();
        int m=mat[0].size();
        int cnt_max=0;
        int index=-1;
        for(int i=0;i<n;i++){
            sort(mat[i].begin(),mat[i].end());
            int cnt_ones = m-lowerBound(mat[i],m,1);
            if(cnt_ones > cnt_max){
                cnt_max = cnt_ones;
                index=i;
                ans.clear();
                ans.push_back(index);
                ans.push_back(cnt_max);
            }
        }
        return ans;
    }
};
