class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 1;

        for (int k = 2; k <= m && k <= n; ++k) {
            bool found = false;
            for (int i = 0; i + k <= m && !found; ++i) {
                for (int j = 0; j + k <= n && !found; ++j) {
                    int val = 0;
                    for (int x = 0; x < k; ++x) val += grid[i][j+x];

                    bool ok = true;

                    for (int r = i; r < i + k; ++r) {
                        int s = accumulate(grid[r].begin() + j, grid[r].begin() + j + k, 0);
                        if (s != val) { ok = false; break; }
                    }
                    if (!ok) continue;

                    for (int c = j; c < j + k; ++c) {
                        int s = 0;
                        for (int r = i; r < i + k; ++r) s += grid[r][c];
                        if (s != val) { ok = false; break; }
                    }
                    if (!ok) continue;

                    int diag1 = 0, diag2 = 0;
                    for (int d = 0; d < k; ++d) {
                        diag1 += grid[i+d][j+d];
                        diag2 += grid[i+d][j+k-1-d];
                    }
                    if (diag1 != val || diag2 != val) ok = false;

                    if (ok) { ans = k; found = true; }
                }
            }
        }

        return ans;
    }};