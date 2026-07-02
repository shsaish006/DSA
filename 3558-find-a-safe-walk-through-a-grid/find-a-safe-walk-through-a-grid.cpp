class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& a, int h) {
        int m = a.size(), n = a[0].size();
        deque<pair<int,int>> q;
        vector<vector<int>> d(m, vector<int>(n, 1e9));
        int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};

        d[0][0] = a[0][0];
        q.push_front({0,0});
        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop_front();
            for(int i=0;i<4;i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx<0||ny<0||nx>=m||ny>=n) continue;
                int w = d[x][y] + a[nx][ny];
                if(w < d[nx][ny]) {
                    d[nx][ny] = w;
                    if(a[nx][ny]) q.push_back({nx,ny});
                    else q.push_front({nx,ny});
                }
            }
        }
        return d[m-1][n-1] < h;
    }
};