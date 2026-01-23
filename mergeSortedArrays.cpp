class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1=a.size(),n2=b.size();
        int m= n1+n2;
        int ind2=m/2;
        int ind1=ind2-1;
        int ele1=-1,ele2=-1;
        int i=0,j=0,cnt=0;
        while(i<n1&&j<n2){
            if(a[i]<b[j]){
                if(cnt==ind1)   ele1=a[i];
                if(cnt==ind2)   ele2=a[i];
                cnt++;
                i++;
            }
            else{
                if(cnt==ind1)   ele1=b[j];
                if(cnt==ind2)   ele2=b[j];
                cnt++;
                j++;
            }
        }
        while(i<n1){
                if(cnt==ind1)   ele1=a[i];
                if(cnt==ind2)   ele2=a[i];
                cnt++;
                i++;
            }
        while(j<n2){
                if(cnt==ind1)   ele1=b[j];
                if(cnt==ind2)   ele2=b[j];
                cnt++;
                j++;
            }
        if(m%2==0)  {
            return (double)((double)(ele1+ele2))/2.0;
        }
        return ele2;
    }
};
