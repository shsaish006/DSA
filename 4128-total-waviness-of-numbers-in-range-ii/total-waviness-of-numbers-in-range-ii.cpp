using ll = long long;

class Solution {
public:
    string s;
    pair<ll,ll> dp[20][11][11][2][2];
    bool vis[20][11][11][2][2];

    pair<ll,ll> dfs(int i, int a, int b, int st, int t) {
        if (i == s.size()) return {1, 0};

        if (vis[i][a][b][st][t])
            return dp[i][a][b][st][t];

        vis[i][a][b][st][t] = 1;

        ll cnt = 0, wav = 0;
        int lim = t ? s[i] - '0' : 9;

        for (int d = 0; d <= lim; d++) {
            int nt = t && (d == lim);

            if (!st && d == 0) {
                auto p = dfs(i + 1, 10, 10, 0, nt);
                cnt += p.first;
                wav += p.second;
            } else {
                auto p = dfs(i + 1, b, d, 1, nt);

                ll add = 0;
                if (a != 10) {
                    if ((b > a && b > d) || (b < a && b < d))
                        add = p.first;
                }

                cnt += p.first;
                wav += p.second + add;
            }
        }

        return dp[i][a][b][st][t] = {cnt, wav};
    }

    ll f(ll n) {
        if (n < 100) return 0;
        s = to_string(n);
        memset(vis, 0, sizeof(vis));
        return dfs(0, 10, 10, 0, 1).second;
    }

    long long totalWaviness(long long l, long long r) {
        return f(r) - f(l - 1);
    }
};