class Solution(object):
    def findTargetSumWays(self, arr, target):
        
        n = len(arr)
        summ = sum(arr)
        if (summ - target) % 2 != 0 or summ - target < 0: return 0
        target = (summ - target)// 2
        dp = [[0]*(target+1) for _ in range(n+1)]

        for i in range(n+1):
            dp[i][0] = 1

        for i in range(1, n+1):
            for j in range(0, target+1):
                dp[i][j] = dp[i-1][j]
                if arr[i-1] <= j:
                    dp[i][j] = dp[i][j] + dp[i-1][j-arr[i-1]]
                    

        return dp[n][target]
