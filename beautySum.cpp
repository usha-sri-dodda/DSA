class Solution {
public:
    int beautySum(string s) 
    {
        int n = s.size();
        int count = 0;
        for(int i = 0; i < n; i++)
        {   vector<int> freq(26, 0);
            for(int j = i; j < n; j++)
            {
                freq[s[j] - 'a']++;
                int mx = 0, mn = INT_MAX;
                for(auto &s: freq)
                {
                    if(s > 0)
                    {
                        mx = max(s, mx);
                        mn = min(s, mn);
                    }
                }
                count += mx - mn;
            }
        }

        return count;
    }
};
