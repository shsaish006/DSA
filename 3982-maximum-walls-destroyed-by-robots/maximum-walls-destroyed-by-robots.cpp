// class Solution {
// public:
//     int maxWalls(vector<int>& a, vector<int>& b, vector<int>& c) {
//         int n = a.size();
//         vector<pair<int,int>> d(n);
//         for (int i = 0; i < n; i++) d[i] = {a[i], b[i]};
//         sort(d.begin(), d.end());
//         sort(c.begin(), c.end());

//         vector<vector<int>> dp(n, vector<int>(2));
//         for (int i = 0; i < 2; i++) {
//             int val = d[0].first - d[0].second;
//             int curr = lower_bound(c.begin(), c.end(), val) - c.begin();
//             int cnt = lower_bound(c.begin(), c.end(), d[0].first + 1) - c.begin();
//             dp[0][i] = cnt - curr;

//             val = d[0].first + d[0].second;
//             curr = lower_bound(c.begin(), c.end(), d[0].first) - c.begin();
//             cnt = lower_bound(c.begin(), c.end(), val + 1) - c.begin();
//             dp[0][i] = max(dp[0][i], cnt - curr);
//         }

//         for (int i = 1; i < n; i++) {
//             for (int j = 0; j < 2; j++) {
//                 int val = d[i].first - d[i].second;
//                 val = max(val, d[i - 1].first + 1);
//                 int curr = lower_bound(c.begin(), c.end(), val) - c.begin();
//                 int cnt = lower_bound(c.begin(), c.end(), d[i].first + 1) - c.begin();
//                 dp[i][j] = dp[i - 1][0] + cnt - curr;

//                 val = d[i].first + d[i].second;
//                 if (i + 1 < n) {
//                     if (j == 0) val = min(val, d[i + 1].first - d[i + 1].second - 1);
//                     else val = min(val, d[i + 1].first - 1);
//                 }
//                 curr = lower_bound(c.begin(), c.end(), d[i].first) - c.begin();
//                 cnt = lower_bound(c.begin(), c.end(), val + 1) - c.begin();
//                 dp[i][j] = max(dp[i][j], dp[i - 1][1] + cnt - curr);
//             }
//         }

//         return dp[n - 1][1];
//     }
// };
class Solution {
public:
    int maxWalls(vector<int>& a, vector<int>& b, vector<int>& c) {
        int n = a.size();
        vector<pair<int,int>> d(n);
        for (int i = 0; i < n; i++) d[i] = {a[i], b[i]};
        sort(d.begin(), d.end());
        sort(c.begin(), c.end());

        vector<vector<int>> dp(n, vector<int>(2, -1));

        auto dfs = [&](auto&& self, int i, int j) -> int {
            if (i < 0) return 0;
            if (dp[i][j] != -1) return dp[i][j];

            int val = d[i].first;
            int cnt = d[i].second;

            int curr = val - cnt;
            if (i) curr = max(curr, d[i - 1].first + 1);
            int l = lower_bound(c.begin(), c.end(), curr) - c.begin();
            int r = lower_bound(c.begin(), c.end(), val + 1) - c.begin();
            int ans = self(self, i - 1, 0) + r - l;

            curr = val + cnt;
            if (i + 1 < n) {
                if (j == 0) curr = min(curr, d[i + 1].first - d[i + 1].second - 1);
                else curr = min(curr, d[i + 1].first - 1);
            }
            l = lower_bound(c.begin(), c.end(), val) - c.begin();
            r = lower_bound(c.begin(), c.end(), curr + 1) - c.begin();
            ans = max(ans, self(self, i - 1, 1) + r - l);

            return dp[i][j] = ans;
        };

        return dfs(dfs, n - 1, 1);
    }
};