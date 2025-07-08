class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        vector<int> startTimes(n);
        for (int i = 0; i < n; ++i) {
            startTimes[i] = events[i][0];
        }

        for (int i = n - 1; i >= 0; --i) {
            int nextIdx = upper_bound(startTimes.begin(), startTimes.end(), events[i][1]) - startTimes.begin();
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = max(dp[i + 1][j], events[i][2] + dp[nextIdx][j - 1]);
            }
        }

        return dp[0][k];
    }
};
