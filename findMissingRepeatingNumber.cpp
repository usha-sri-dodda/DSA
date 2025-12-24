class Solution {
public:
    vector<int> findMissingRepeatingNumber(vector<int> a){
        int n=a.size();
        int xr=0,i=0;
        for(i=0;i<n;i++){
            xr=xr^a[i];
            xr=xr^(i+1);
        }
        int bitNum=xr&~(xr-1);
        int one=0,zero=0;
        for(int i=0;i<n;i++){
            if((a[i]&bitNum)!=0)    one=one^a[i];
            else zero=zero^a[i];
        }
        for(i=1;i<=n;i++){
            if((i&bitNum)!=0)    one=one^i;
            else zero=zero^i;
        }
        int cnt=0;
        for(i=0;i<n;i++){
            if(a[i]==zero)  cnt++;
        }
        if(cnt==2)  return {zero,one};
        return {one,zero};
    }
};
