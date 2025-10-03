class Solution {
public:
    int trapRainWater(vector<vector<int>>& h) {
        int m = h.size(), n = h[0].size();
        vector<vector<bool>> v(m, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> q;
        for (int i = 0; i < m; i++) {
            q.push({h[i][0], i, 0}); v[i][0] = true;
            q.push({h[i][n - 1], i, n - 1}); v[i][n - 1] = true;
        }
        for (int j = 1; j < n - 1; j++) {
            q.push({h[0][j], 0, j}); v[0][j] = true;
            q.push({h[m - 1][j], m - 1, j}); v[m - 1][j] = true;
        }
        int res = 0;
        int d[5] = {1, 0, -1, 0, 1};
        while (!q.empty()) {
            auto cur = q.top(); q.pop();
            for (int k = 0; k < 4; k++) {
                int x = cur[1] + d[k], y = cur[2] + d[k + 1];
                if (x < 0 || x >= m || y < 0 || y >= n || v[x][y]) continue;
                res += max(0, cur[0] - h[x][y]);
                q.push({max(h[x][y], cur[0]), x, y});
                v[x][y] = true;
            }
        }
        return res;
    }
};
