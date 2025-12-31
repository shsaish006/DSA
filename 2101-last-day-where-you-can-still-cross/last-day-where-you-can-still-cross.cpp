class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = row * col;
        vector<int> p(n + 2), r(n + 2);
        int s = n, t = n + 1;
        for (int i = 0; i < n + 2; i++) p[i] = i;
        auto f = [&](int x) {
            while (p[x] != x) {
                p[x] = p[p[x]];
                x = p[x];
            }
            return x;
        };
        auto u = [&](int a, int b) {
            a = f(a);
            b = f(b);
            if (a == b) return;
            if (r[a] < r[b]) swap(a, b);
            p[b] = a;
            if (r[a] == r[b]) r[a]++;
        };
        vector<vector<int>> g(row, vector<int>(col, 0));
        int d[5] = {0, 1, 0, -1, 0};
        for (int i = cells.size() - 1; i >= 0; i--) {
            int x = cells[i][0] - 1;
            int y = cells[i][1] - 1;
            g[x][y] = 1;
            int id = x * col + y;
            if (x == 0) u(id, s);
            if (x == row - 1) u(id, t);
            for (int k = 0; k < 4; k++) {
                int nx = x + d[k];
                int ny = y + d[k + 1];
                if (nx >= 0 && nx < row && ny >= 0 && ny < col && g[nx][ny]) {
                    u(id, nx * col + ny);
                }
            }
            if (f(s) == f(t)) return i;
        }
        return 0;
    }};