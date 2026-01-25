class Solution{
public:
    int findMedian(vector<vector<int>>&mat) {
      int row=mat.size();
      int col=mat[0].size();
      int low=mat[0][0];
      int high=mat[0][col-1];
      for(int i=0;i<row;i++){
        low=min(low,mat[i][0]);
        high=max(high,mat[i][col-1]);
      }
      int mid;
      while(low<high)
      {
        mid=low+(high-low)/2;
        int cnt=0;
        for(int i=0;i<row;i++){
             cnt+=upper_bound(mat[i].begin(),mat[i].end(),mid)
        }
        if(cnt<(row*col+1)/2)   low=mid+1;
        else high=mid-1;
      }
      return low;
    }
};
