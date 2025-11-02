class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> g(m, vector<int>(n, 0));
        for (auto &e : guards) g[e[0]][e[1]] = 2;
        for (auto &e : walls) g[e[0]][e[1]] = 3;

        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        for (auto &e : guards) {
            for (auto [dx, dy] : dirs) {
                int x = e[0] + dx, y = e[1] + dy;
                while (x >= 0 && x < m && y >= 0 && y < n && g[x][y] != 2 && g[x][y] != 3) {
                    if (g[x][y] == 0) g[x][y] = 1;
                    x += dx;
                    y += dy;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (g[i][j] == 0)
                    ++ans;
        return ans;
    }
};

