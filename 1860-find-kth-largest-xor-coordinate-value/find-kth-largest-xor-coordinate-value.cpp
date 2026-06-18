class Solution {
public:
    int kthLargestValue(vector<vector<int>>& a, int k) {
        int m = a.size(), n = a[0].size();
        vector<int> v;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = a[i - 1][j - 1] ^ dp[i - 1][j] ^ dp[i][j - 1] ^ dp[i - 1][j - 1];
                v.push_back(dp[i][j]);
            }
        }
        sort(v.begin(), v.end(), greater<int>());
        return v[k - 1];
    }
};