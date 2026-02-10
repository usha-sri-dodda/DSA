class Solution {
public:
    int climbStairs(int n) {
        
        int prev = 1, curr = 1;
        for (int i = 2; i <= n; i++) {
            int temp = curr;
            curr = prev + curr;
            prev = temp;
        }
        return curr;
        // int a=climbStairs(n-1);
        // int b=n-a;
        // return a+b;
    }
};
