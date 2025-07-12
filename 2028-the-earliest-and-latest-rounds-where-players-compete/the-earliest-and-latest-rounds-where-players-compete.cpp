class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        using Pair = pair<int, int>;
        // dp[l][r][k] = {earliest, latest} when first is l-th from front,
        // second is r-th from end, total k players.
        vector dp(n+1, vector(n+1, vector<Pair>(n+2, {0,0})));
        auto solve = [&](auto self, int l, int r, int k) -> Pair {
            if (l == r) return {1, 1};
            if (l > r) swap(l, r);
            Pair &res = dp[l][r][k];
            if (res.first != 0) return res;

            int earliest = INT_MAX, latest = INT_MIN;
            for (int i = 1; i <= l; ++i) {
                for (int j = l - i + 1; j <= r - i; ++j) {
                    if (i + j > (k + 1) / 2 || i + j < l + r - k / 2) 
                        continue;
                    auto [e, ll] = self(self, i, j, (k + 1) / 2);
                    earliest = min(earliest, e + 1);
                    latest   = max(latest, ll + 1);
                }
            }
            return res = {earliest, latest};
        };

        auto [e, l] = solve(solve, firstPlayer, n - secondPlayer + 1, n);
        return {e, l};
    }
};
