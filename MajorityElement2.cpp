class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int c1=0,c2=0;
        int e1=INT_MIN,e2=INT_MIN;
        for(int i=0;i<n;i++){
            if(c1==0&&nums[i]!=e2){
                c1=1;e1=nums[i];
            }
            else if(c2==0&&nums[i]!=e1){
                c2=1;
                e2=nums[i];
            }
            else if(nums[i]==e1)    c1++;
            else if(nums[i]==e2)    c2++;
            else    c1--,c2--;
        }
        int cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==e1)     cnt1++;
            else if(nums[i]==e2)    cnt2++;
        }
        vector<int> res;
        int  mini=(int)(n/3)+1;
        if(cnt1>=mini)  res.push_back(e1);
        if(cnt2>=mini)  res.push_back(e2);
        sort(res.begin(),res.end());
        return res;
    }
};
