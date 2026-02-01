class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int l=0;
        int sign=1;
        while(l<n&&s[l]==' ')   l++;
        if(l<n){
            if(s[l]=='-')  sign=-1,l++;
            else if(s[l]=='+')  sign=1,l++;
        }
        long res=0;
        while(l<n&&isdigit(s[l])){
            res=res*10+(s[l]-'0');
            l++;
            if (sign * res > INT_MAX) return INT_MAX;
            if (sign * res < INT_MIN) return INT_MIN;
        }
        return sign*res;
    }
};
