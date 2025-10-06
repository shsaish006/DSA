class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        int ans = 0;
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto [t, x, y] = pq.top();
            pq.pop();
            if (vis[x][y]) continue;
            vis[x][y] = 1;
            ans = max(ans, t);
            if (x == n - 1 && y == n - 1) return ans;
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny]) {
                    pq.push({grid[nx][ny], nx, ny});
                }
            }
        }
        return ans;
    }
};
