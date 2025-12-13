#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> generateRow(int rows){
            long long res=1;
            vector<int> res;
            res.push_back(1);
            for(int i=1;i<rows;i++){
                res=res*(rows-i);
                res/=i;

            }
            return ans;
        }

        vector<vector<int>> generate(int numRows){
            vector<vector<int>> ans;
            for(int i=1;i<numRows;i++){
                ans.push_back(generateRow(numRows));
            }
            return ans;
        }
}