class Solution {
public:
    vector<int> findMissingRepeatingNumber(vector<int> a){
        int n=a.size();
        long long s1n=(n*(n+1))/2;
        long long s2n=n*(n+1)*(2n+1)/6;
        long long s1,s2;
        for(int i=0;i<n;i++){
            s1+=a[i];
            s2+=(a[i]*a[i]);
        }
        long long diff1=s1-s1n;
        long long diff2=s2-s2n;
        long long sum=diff2/diff1;
        int n1=(int)(sum+diff1)/2;
        int n2=(int)(sum-n1);
        return {n1,n2};

    }
};
