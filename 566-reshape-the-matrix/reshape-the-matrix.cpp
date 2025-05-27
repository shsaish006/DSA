class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m=mat.size(),n=mat[0].size();
        if(m*n !=r*c) return mat;
        vector<vector<int>> res(r,vector<int>(c));
        int x=0,y=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                res[i][j]=mat[x][y++];
                if(y==n){
                    y=0;
                    x++;

                }
            }
        }
        return res;
    }
};