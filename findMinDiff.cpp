class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        int n=a.size();
        if (m == 0 || n < m)
        return -1;

    sort(a.begin(), a.end());

    int minDiff = INT_MAX;

    for (int i = 0; i + m - 1 < n; i++) {
        int diff = a[i + m - 1] - a[i];
        minDiff = min(minDiff, diff);
    }

    return minDiff;
    }
};
