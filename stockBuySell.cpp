#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate maximum profit using single pass
    int stockbuySell(vector<int>& prices) {
        // Initialize the minimum price to a large number
        int minPrice = INT_MAX;

        // Initialize the maximum profit to 0
        int maxProfit = 0;

        // Traverse each price in the array
        for (int price : prices) {
            // If current price is less than minPrice, update minPrice
            if (price < minPrice) {
                minPrice = price;
            }
            // Else calculate profit and update maxProfit if it's greater
            else {
                maxProfit = max(maxProfit, price - minPrice);
            }
        }

        // Return the maximum profit found
        return maxProfit;
    }
};

//Approach 2
int dp[100001];
    int solve(int idx,vector<int>& prices, vector<int>& suff){
        int n=prices.size();
        if(idx==n-1)  return 0;
        if(dp[idx]!=-1) return dp[idx];
        int ans =suff[idx+1]-prices[idx];
        
        ans=max(ans,solve(idx+1,prices,suff));
        return dp[idx]=ans;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        memset(dp,-1,sizeof(dp));
        vector<int> suff_max(n);
        suff_max[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--){
            suff_max[i]=max(prices[i],suff_max[i+1]);
        }

        return solve(0,prices,suff_max);
    }
