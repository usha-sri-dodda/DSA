class Solution {
public:
    int dp[101];
    int solve(int idx,string s){
        int cnt=0;
        int n=s.size();
        if(idx==n) return 1;
        if(s[idx]=='0') return 0;
        if(dp[idx]!=-1) return dp[idx];
        cnt+=solve(idx+1,s);
        if(idx+1<n){
            int num=(s[idx]-'0')*10+(s[idx+1]-'0');
            if(num>=1&& num<=26){
                cnt+=solve(idx+2,s);
            }
        }
        return dp[n]=cnt;

    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(0,s);
    }
};
