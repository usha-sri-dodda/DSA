class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z=0,i=0,n=nums.size();
        int h=n-1;
        while(i<=h){
            if(nums[i]==0)  {
                swap(nums[i],nums[z]);z++;i++;
            }
            else if(nums[i]==1){
               i++;
            }
            else {
                swap(nums[i],nums[h]);h--;
            }
        }
    }
};
