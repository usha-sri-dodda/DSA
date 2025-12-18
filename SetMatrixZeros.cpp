class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int col0=1;
        int i=0,j=0;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(mat[i][j]==0)    {
                    mat[i][0]=0;
                    if(j!=0){
                        mat[0][j]=0;
                    }
                    else{
                        col0=0;
                    }
                }
            }
        }
        for(i=1;i<m;i++){
            for(j=1;j<n;j++){
                if(mat[0][j]==0||mat[i][0]==0)  mat[i][j]=0;
            }
        }
        if(mat[0][0]==0){
            for(j=0;j<n;j++)    mat[0][j]=0;
        }
        
        if(col0==0){
            for(i=0;i<m;i++)    mat[i][0]=0;
        }
    }
};
