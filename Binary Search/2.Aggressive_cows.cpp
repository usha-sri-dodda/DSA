class Solution {
  public:
    bool check(vector<int>& arr, int k, int d){
        int count = 1, last = arr[0];
        int n = arr.size();
        for(int i = 1; i < n; i++){
            if(arr[i] - last >=d)   count++, last = arr[i];
            
        }
        return count >= k;
    }
    int aggressiveCows(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int low = 1, ans = 0;
        int high = arr[n - 1] - arr[0];
        while(low <= high){
            int mid = low + (high - low)/2;
            if(check(arr, k, mid)) ans = mid, low = mid + 1;
            else high = mid - 1;
        }
        return ans;
    }
};
