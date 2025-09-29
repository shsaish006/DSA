class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n - 1, values, dp);
    }

private:
    int solve(int i, int j, vector<int>& v, vector<vector<int>>& dp) {
        if (i + 1 == j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            ans = min(ans, solve(i, k, v, dp) + solve(k, j, v, dp) + v[i] * v[k] * v[j]);
        }
        return dp[i][j] = ans;
    }};