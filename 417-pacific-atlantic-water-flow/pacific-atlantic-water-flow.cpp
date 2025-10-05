class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int m = h.size(), n = h[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> v1(m, vector<int>(n)), v2(m, vector<int>(n));
        int d[5] = {-1, 0, 1, 0, -1};
        function<void(int,int,vector<vector<int>>&)> dfs = [&](int x, int y, vector<vector<int>>& v){
            v[x][y] = 1;
            for(int k=0;k<4;k++){
                int nx=x+d[k], ny=y+d[k+1];
                if(nx>=0 && ny>=0 && nx<m && ny<n && !v[nx][ny] && h[nx][ny]>=h[x][y])
                    dfs(nx,ny,v);
            }
        };
        for(int i=0;i<m;i++) dfs(i,0,v1), dfs(i,n-1,v2);
        for(int j=0;j<n;j++) dfs(0,j,v1), dfs(m-1,j,v2);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(v1[i][j] && v2[i][j])
                    ans.push_back({i,j});
        return ans;
    }
};