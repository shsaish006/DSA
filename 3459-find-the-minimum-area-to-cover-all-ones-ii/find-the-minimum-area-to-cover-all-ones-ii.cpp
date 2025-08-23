#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int inf = 1e9, ans = m * n;

        auto rect = [&](int x1, int y1, int x2, int y2) {
            int r1 = m, c1 = n, r2 = -1, c2 = -1;
            for (int i = x1; i <= x2; i++) {
                for (int j = y1; j <= y2; j++) {
                    if (grid[i][j]) {
                        r1 = min(r1, i);
                        c1 = min(c1, j);
                        r2 = max(r2, i);
                        c2 = max(c2, j);
                    }
                }
            }
            if (r2 == -1) return inf;
            return (r2 - r1 + 1) * (c2 - c1 + 1);
        };

        // horizontal 3-partition
        for (int a = 0; a < m - 2; a++) {
            for (int b = a + 1; b < m - 1; b++) {
                ans = min(ans, rect(0, 0, a, n - 1) + rect(a + 1, 0, b, n - 1) + rect(b + 1, 0, m - 1, n - 1));
            }
        }

        // vertical 3-partition
        for (int a = 0; a < n - 2; a++) {
            for (int b = a + 1; b < n - 1; b++) {
                ans = min(ans, rect(0, 0, m - 1, a) + rect(0, a + 1, m - 1, b) + rect(0, b + 1, m - 1, n - 1));
            }
        }

        // L-shaped partitions
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                ans = min(ans, rect(0, 0, i, j) + rect(0, j + 1, i, n - 1) + rect(i + 1, 0, m - 1, n - 1));
                ans = min(ans, rect(0, 0, i, n - 1) + rect(i + 1, 0, m - 1, j) + rect(i + 1, j + 1, m - 1, n - 1));
                ans = min(ans, rect(0, 0, i, j) + rect(i + 1, 0, m - 1, j) + rect(0, j + 1, m - 1, n - 1));
                ans = min(ans, rect(0, 0, m - 1, j) + rect(0, j + 1, i, n - 1) + rect(i + 1, j + 1, m - 1, n - 1));
            }
        }

        return ans;
    }};
