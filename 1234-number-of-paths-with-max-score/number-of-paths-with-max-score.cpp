class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& b) {
        int n = b.size(), mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        vector<vector<int>> cnt(n + 1, vector<int>(n + 1));

        dp[n - 1][n - 1] = 0;
        cnt[n - 1][n - 1] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (b[i][j] == 'X' || (i == n - 1 && j == n - 1)) continue;

                int mx = max({dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1]});
                if (mx == -1) continue;

                dp[i][j] = mx + (isdigit(b[i][j]) ? b[i][j] - '0' : 0);

                if (dp[i + 1][j] == mx) cnt[i][j] = (cnt[i][j] + cnt[i + 1][j]) % mod;
                if (dp[i][j + 1] == mx) cnt[i][j] = (cnt[i][j] + cnt[i][j + 1]) % mod;
                if (dp[i + 1][j + 1] == mx) cnt[i][j] = (cnt[i][j] + cnt[i + 1][j + 1]) % mod;
            }
        }

        if (dp[0][0] == -1) return {0, 0};
        return {dp[0][0], cnt[0][0]};
    }
};