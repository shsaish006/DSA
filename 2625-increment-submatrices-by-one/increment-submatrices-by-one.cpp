class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& q) {
        vector<vector<int>> a(n, vector<int>(n, 0));

        for (auto &v : q) {
            int x1 = v[0], y1 = v[1], x2 = v[2], y2 = v[3];
            a[x1][y1]++;

            if (x2 + 1 < n) a[x2 + 1][y1]--;
            if (y2 + 1 < n) a[x1][y2 + 1]--;
            if (x2 + 1 < n && y2 + 1 < n) a[x2 + 1][y2 + 1]++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int u = (i ? a[i-1][j] : 0);
                int l = (j ? a[i][j-1] : 0);
                int d = (i && j ? a[i-1][j-1] : 0);
                a[i][j] = a[i][j] + u + l - d;
            }
        }

        return a;
    }
};