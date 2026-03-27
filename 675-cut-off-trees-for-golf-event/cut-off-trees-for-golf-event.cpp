class Solution {
public:
    int bfs(vector<vector<int>> &forest, int sx, int sy, int tx, int ty){
        if(sx==tx && sy==ty) return 0;
        int m=forest.size(), n=forest[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(m,vector<int>(n,0));
        q.push({sx,sy});
        vis[sx][sy]=1;
        int d=0;
        int dir[5]={-1,0,1,0,-1};
        while(!q.empty()){
            int sz=q.size();
            d++;
            while(sz--){
                auto p=q.front(); q.pop();
                int x=p.first, y=p.second;
                for( int k=0;k<4;k++){
                    int nx=x+dir[k], ny=y+dir[k+1];
                    if(nx>=0 && ny>=0 && nx<m && ny<n && forest[nx][ny]!=0 && !vis[nx][ny]){
                        if(nx==tx && ny==ty) return d;
                        vis[nx][ny]=1;
                        q.push({nx,ny});
                    }
                }

            }
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        int m=forest.size(), n=forest[0].size();
        vector<vector<int>> t;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(forest[i][j]>1)
                    t.push_back({forest[i][j],i,j});
                    sort(t.begin(),t.end());
                    int x=0, y=0, ans=0;
                    for(auto &v:t){
                        int d=bfs(forest,x,y,v[1],v[2]);
                        if(d==-1) return -1;
                        ans+=d;
                        x=v[1];
                        y=v[2];
                    }
                    return ans;
        
    }
};