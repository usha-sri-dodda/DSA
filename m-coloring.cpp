class Solution {
  public:
    bool issafe(int vertex, int col, vector<int> adj[], vector<int> color){
       
        for(auto it : adj[vertex]){
            if(color[it] != -1 && color[it] == col) return false;
        }
        return true;
    }
   bool cancolor(int ind, vector<int>& color, int m, vector<int> adj[]){
        if(ind==color.size()){
            return true;
        }
        for(int i = 0; i < m; i++){
            if(issafe(ind,i,adj,color)) {
    
                color[ind] = i;
                if(cancolor(ind+1, color, m, adj))  return true;
                color[ind] = -1;
            }
        }
        
        return false;
       
   }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        // build adjacency matrix,
        // function cancolor
        // check if it is safe to color with the current color
        // if yes color it .
         vector<int> adj[v];
         
         for(auto it : edges){
             adj[it[0]].push_back(it[1]);
             adj[it[1]].push_back(it[0]);
         }
         
         vector<int> color(v,-1);
         return cancolor(0,color,m,adj);
    }
};
