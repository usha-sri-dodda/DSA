class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp ;
        for(char c: s)  mp[c]++;
        // move map to vector
        vector<pair<char,int>> v(mp.begin(), mp.end());

        // sort by second element (value)
        sort(v.begin(), v.end(), [](auto &a, auto &b){
            return a.second > b.second;  
        });
        string ans="";
        for(const auto& i : v){ 
            ans.append(i.second,i.first); 
         } 
        return ans;
        }
};
