class Solution {
public:
    string reverse(string& s){
        int n=s.size();
        int l=0,r=n-1;
        while(l<r){
            swap(s[l++],s[r--]);
        }
        return s;
    }
    string reverseWords(string s) {
        
        string ans="";
        string temp="";
        int n=s.size();
        int left=0,right=n-1,r=n-1;
        while(left<n&&s[left]==' ') left++;
        while(right>=0&&s[right]==' ')  right--;
        string str=s.substr(left,right+1);
        while(r>=0){
            if(str[r]!=' ')   temp+=str[r];
            else if(str[r]==' ') ans+=reverse(temp),ans+=' ',temp="";
            r--;
        }
        ans+=reverse(temp);
        return ans;
    }
};
