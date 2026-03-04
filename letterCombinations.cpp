class Solution {
public:
    unordered_map<char,vector<char>> mp = {
        {'2' , {'a','b','c'}},
        {'3' , {'d','e','f'}},
        {'4' , {'g','h','i'}},
        {'5' , {'j','k','l'}},
        {'6' , {'m','n','o'}},
        {'7' , {'p','q','r','s'}},
        {'8' , {'t','u','v'}},
        {'9' , {'w','x','y','z'}}
    };
    void help(string s, int idx, int n, vector<string>& res, string& temp){
        if(idx==n) {
            res.push_back(temp);
            return;
        }
        char c = s[idx];
        int char_size = mp[c].size();
        for(int j = 0;j<char_size; j++){
            temp.push_back(mp[c][j]);
            help(s,idx+1,n,res,temp);
            temp.pop_back();
        } 
        return ;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        int n = digits.size();
        string temp;
        help(digits,0,n,res,temp);
        return res;
    }
};
