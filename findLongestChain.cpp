class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& v1, const vector<int>& v2) {
            return v1[1] < v2[1];
        });
        int cur = INT_MIN, cnt=0;
        for(const auto& pair: pairs){
            if(cur<pair[0]){
                cur = pair[1];
                cnt++;
            }
        }
        return cnt;

    }
};
