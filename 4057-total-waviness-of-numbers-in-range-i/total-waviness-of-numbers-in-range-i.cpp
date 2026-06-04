class Solution {
    long long dp[20][11][11][2][20];
    string s;
    pair<long long,long long> dfs(int i, int p1, int p2, int st, int tight) {
        if (i == s.size()) return {1, 0};
        if (!tight && dp[i][p1][p2][st][0] != -1)
            return {dp[i][p1][p2][st][0], dp[i][p1][p2][st][1]};
            int lim = tight ? s[i] - '0' : 9;
        long long ways = 0, sum = 0;
        for (int d = 0; d <= lim; d++) {
            int nt = tight && (d == lim);
            if (!st && d == 0) {
                auto [w, v] = dfs(i + 1, 10, 10, 0, nt);
                ways += w;
                sum += v;
            } else {
                int add = 0;
                if (st && p2 != 10) {
                    if ((p1 > p2 && p1 > d) || (p1 < p2 && p1 < d))
                        add = 1;
                }
                auto [w, v] = dfs(i + 1, d, p1, 1, nt);
                ways += w;
                sum += v + 1LL * add * w;
            }
        }
        if (!tight) {
            dp[i][p1][p2][st][0] = ways;
            dp[i][p1][p2][st][1] = sum;
        }

        return {ways, sum};
    }
    long long solve(long long x) {
        if (x < 0) return 0;
        s = to_string(x);
        memset(dp, -1, sizeof(dp));
        return dfs(0, 10, 10, 0, 1).second;
    }
public:
    int totalWaviness(int num1, int num2) {
        return solve(num2) - solve(num1 - 1);
    }
};