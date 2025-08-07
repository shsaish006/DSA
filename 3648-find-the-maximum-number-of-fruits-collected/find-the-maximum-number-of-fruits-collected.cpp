class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& grid) {
        int n = grid.size();
        const int INF = -(1 << 29);
        vector<vector<int>> dp(n, vector<int>(n, INF));

        dp[0][n - 1] = grid[0][n - 1];

        for (int r = 1; r < n; ++r) {
            for (int c = r + 1; c < n; ++c) {
                int val = max(dp[r - 1][c], dp[r - 1][c - 1]);
                if (c + 1 < n) val = max(val, dp[r - 1][c + 1]);
                dp[r][c] = val + grid[r][c];
            }
        }

        dp[n - 1][0] = grid[n - 1][0];

        for (int c = 1; c < n; ++c) {
            for (int r = c + 1; r < n; ++r) {
                int val = max(dp[r][c - 1], dp[r - 1][c - 1]);
                if (r + 1 < n) val = max(val, dp[r + 1][c - 1]);
                dp[r][c] = val + grid[r][c];
            }
        }

        int res = dp[n - 2][n - 1] + dp[n - 1][n - 2];
        for (int i = 0; i < n; ++i) res += grid[i][i];
        return res;
    }
};
