#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the missing number using XOR approach
    int missingNumber(vector<int>& a) {
        int N=a.size();
        int xor1 = 0, xor2 = 0;

        for (int i = 0; i < N ; i++) {
            xor2 = xor2 ^ a[i];      
            xor1 = xor1 ^ (i + 1);   
        }

       
        return xor1 ^ xor2;
    }
};
