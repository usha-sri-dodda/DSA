class Solution {
public:
    double power(double x,long long n,double res){
        if(n<1) return 1.0*res;
        if(n%2==1)  res*=x,n=n-1;
        else x=x*x,n=n/2;
        return power(x,n,res);
    }
    double myPow(double x, int n) {
        double res=1;
        long long nn=n;
        if(nn<0)    nn=-nn;
        res=power(x,nn,res);
        if(n<0) res=1.0/res;
        return res;
    }
};
