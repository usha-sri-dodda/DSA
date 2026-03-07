class Solution {
public:
    bool check(int color, int n, vector<int> adj[n], int ind, vector<int>& ans){
       
        for(auto i : adj[ind]){
            if(ans[i] != 0 && ans[i] == color) return false;
        }
        return true;
    }
    bool solve(int n, vector<int> adj[n], int ind, vector<int>& ans){
        if(ind == n)    return true;
        for(int i = 1; i < 5; i++){
            
            if(check(i, n, adj, ind, ans)){
                ans[ind] = i;
                if(solve(n, adj, ind + 1, ans))
                     return true;
                ans[ind] = 0;
            }
        }
        return false;
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> ans(n,0);
        vector<int> adj[n];
        for(auto it : paths){
            adj[it[0]-1].push_back(it[1]-1);
            adj[it[1]-1].push_back(it[0]-1);
        }
        solve(n, adj, 0, ans);
        return ans;
    }
};
