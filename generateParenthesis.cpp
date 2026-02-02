class Solution {
public:
    bool isVps(string s){
        stack<char> stk;
        for(char c:s){
            if(c=='(')  stk.push(c);
            else if(c==')'&&!stk.empty()&&stk.top()=='(') stk.pop(); 
            else return false;
        }
        return stk.empty();
    }
    void fun(int i,int n,vector<string>& vec,string &s){
        if(i==n)   { 
            if(isVps(s))
                vec.push_back(s);
            return;
            }
            
        s.push_back('(');
        fun(i+1,n,vec,s);
        s.pop_back();

        s.push_back(')');
        fun(i+1,n,vec,s);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        string s="";
        fun(0,2*n,vec,s);
        return vec;
    }
};
