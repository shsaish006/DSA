class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& g) {
        int n = g.size();
        vector<vector<int>> d(n, vector<int>(n, 1e9));
        queue<pair<int,int>> q;
        int dir[5]={-1,0,1,0,-1};

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(g[i][j]){
                    d[i][j]=0;
                    q.push({i,j});
                }

        while(!q.empty()){
            auto [x,y]=q.front(); q.pop();
            for(int k=0;k<4;k++){
                int nx=x+dir[k],ny=y+dir[k+1];
                if(nx>=0&&ny>=0&&nx<n&&ny<n&&d[nx][ny]>d[x][y]+1){
                    d[nx][ny]=d[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }

        int l=0,r=2*n;
        while(l<r){
            int m=(l+r+1)/2;
            if(d[0][0]<m||d[n-1][n-1]<m){
                r=m-1;
                continue;
            }

            vector<vector<int>> vis(n,vector<int>(n));
            queue<pair<int,int>> qq;
            qq.push({0,0});
            vis[0][0]=1;

            while(!qq.empty()){
                auto [x,y]=qq.front(); qq.pop();
                for(int k=0;k<4;k++){
                    int nx=x+dir[k],ny=y+dir[k+1];
                    if(nx>=0&&ny>=0&&nx<n&&ny<n&&!vis[nx][ny]&&d[nx][ny]>=m){
                        vis[nx][ny]=1;
                        qq.push({nx,ny});
                    }
                }
            }

            if(vis[n-1][n-1]) l=m;
            else r=m-1;
        }
        return l;
    }
};