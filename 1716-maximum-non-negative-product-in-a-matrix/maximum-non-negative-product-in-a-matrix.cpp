class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int a = grid.size(), b = grid[0].size(), val = 1000000007;
        vector<vector<long long>> nums(a, vector<long long>(b)), nxt(a, vector<long long>(b));
        nums[0][0] = nxt[0][0] = grid[0][0];

        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (!i && !j) continue;
                long long curr = grid[i][j];
                long long on = LLONG_MAX, upd = LLONG_MIN;
                if (i) {
                    on = min(on, min(nums[i - 1][j] * curr, nxt[i - 1][j] * curr));
                    upd = max(upd, max(nums[i - 1][j] * curr, nxt[i - 1][j] * curr));
                }
                if (j) {
                    on = min(on, min(nums[i][j - 1] * curr, nxt[i][j - 1] * curr));
                    upd = max(upd, max(nums[i][j - 1] * curr, nxt[i][j - 1] * curr));
                }
                nums[i][j] = on;
                nxt[i][j] = upd;
            }
        }

        long long ans = nxt[a - 1][b - 1];
        return ans < 0 ? -1 : ans % val;
    }
};