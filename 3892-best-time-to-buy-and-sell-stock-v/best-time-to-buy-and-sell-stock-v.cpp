class Solution {
public:
    long long maximumProfit(vector<int>& a, int k) {
        int n = a.size();
        long long f[n][k + 1][3];
        memset(f, 0, sizeof(f));
        for (int j = 1; j <= k; j++) {
            f[0][j][1] = -a[0];
            f[0][j][2] = a[0];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                f[i][j][0] = max({f[i - 1][j][0], f[i - 1][j][1] + a[i], f[i - 1][j][2] - a[i]});
                f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - a[i]);
                f[i][j][2] = max(f[i - 1][j][2], f[i - 1][j - 1][0] + a[i]);
            }
        }
        return f[n - 1][k][0];
    }
};
