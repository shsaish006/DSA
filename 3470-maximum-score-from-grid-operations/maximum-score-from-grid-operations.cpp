using ll = long long;

class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int a = grid.size();

        vector<vector<ll>> nums(a, vector<ll>(a + 1));

        for (int i = 0; i < a; i++) {
            for (int j = 1; j <= a; j++) {
                nums[i][j] = nums[i][j - 1] + grid[j - 1][i];
            }
        }

        vector<vector<ll>> vals(a + 1, vector<ll>(a + 1));
        vector<vector<ll>> nxt(a + 1, vector<ll>(a + 1));
        vector<vector<ll>> upd(a + 1, vector<ll>(a + 1));

        for (int i = 1; i < a; i++) {
            vector<vector<ll>> on(a + 1, vector<ll>(a + 1));

            for (int j = 0; j <= a; j++) {
                for (int k = 0; k <= a; k++) {
                    if (j <= k) {
                        ll curr = nums[i][k] - nums[i][j];
                        on[j][k] = upd[k][0] + curr;
                    } else {
                        ll curr = nums[i - 1][j] - nums[i - 1][k];
                        on[j][k] = upd[k][j];
                        if (vals[k][j] + curr > on[j][k])
                            on[j][k] = vals[k][j] + curr;
                    }
                }
            }

            for (int j = 0; j <= a; j++) {
                vals[j][0] = on[j][0];

                for (int k = 1; k <= a; k++) {
                    ll curr = 0;
                    if (k > j)
                        curr = nums[i][k] - nums[i][j];

                    vals[j][k] = vals[j][k - 1];
                    if (on[j][k] - curr > vals[j][k])
                        vals[j][k] = on[j][k] - curr;
                }

                upd[j][a] = on[j][a];

                for (int k = a - 1; k >= 0; k--) {
                    upd[j][k] = upd[j][k + 1];
                    if (on[j][k] > upd[j][k])
                        upd[j][k] = on[j][k];
                }
            }

            nxt.swap(on);
        }

        ll cnt = 0;

        for (int i = 0; i <= a; i++) {
            if (nxt[0][i] > cnt)
                cnt = nxt[0][i];
            if (nxt[a][i] > cnt)
                cnt = nxt[a][i];
        }

        return cnt;
    }
};