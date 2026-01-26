class Solution {
public:
    // Check if goal is a rotation of s using string doubling method
    bool rotateString(string& s, string& goal) {
        // Strings must be the same length to be rotations of each other
        if (s.length() != goal.length()) return false;
        
        // Concatenate s with itself and check if goal exists in it
        string doubledS = s + s;
        return doubledS.find(goal) != string::npos;
    }
};


class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        int arr[26] = {0};

        for (int i = 0 ; i<s.length(); i++){
            arr[s[i]-'a'] += 1;
            arr[t[i] - 'a'] -= 1;
        }

        for (int check : arr){
            if (check != 0) return false;
        }
        return true;
    }
};
