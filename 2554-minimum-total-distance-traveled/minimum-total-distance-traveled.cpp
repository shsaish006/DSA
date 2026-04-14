class Solution {
public:
    long long minimumTotalDistance(vector<int>& a, vector<vector<int>>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int c = a.size(), d = b.size();
        vector<vector<long long>> dp(d + 1, vector<long long>(c + 1, 1e18));
        for (int i = 0; i <= d; i++) dp[i][c] = 0;

        for (int i = d - 1; i >= 0; i--) {
            for (int j = c - 1; j >= 0; j--) {
                dp[i][j] = dp[i + 1][j];
                long long s = 0;
                for (int k = 0; k < b[i][1] && j + k < c; k++) {
                    s += llabs(a[j + k] - b[i][0]);
                    dp[i][j] = min(dp[i][j], s + dp[i + 1][j + k + 1]);
                }
            }
        }
        return dp[0][0];
    }
};