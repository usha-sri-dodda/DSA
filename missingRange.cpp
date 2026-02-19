class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        unordered_set<int> s;
        for (int x : arr) {
            s.insert(x);
        }
        vector<int> ans;
        for (int x = low; x <= high; ++x) {
            if (s.find(x) == s.end())
                ans.push_back(x);
        }
        return ans;
    }
};
