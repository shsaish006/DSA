class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> nums(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; i++) nums[i][i] = 0;
        for (auto &a : edges) {
            int b = a[0] - 1, c = a[1] - 1;
            nums[b][c] = 1;
            nums[c][b] = 1;
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    nums[i][j] = min(nums[i][j], nums[i][k] + nums[k][j]);
                }
            }
        }

        vector<int> vals(1 << n), nxt(1 << n), upd(n - 1);

        for (int i = 1; i < (1 << n); i++) {
            if ((i & (i - 1)) == 0) continue;

            int cnt = 0, val = 0;
            for (auto &a : edges) {
                int b = a[0] - 1, c = a[1] - 1;
                if ((i >> b & 1) && (i >> c & 1)) cnt++;
            }

            for (int j = 0; j < n; j++) {
                if (i >> j & 1) val++;
            }

            if (cnt != val - 1) continue;

            int curr = 0;
            for (int j = 0; j < n; j++) {
                if (!(i >> j & 1)) continue;
                for (int k = j + 1; k < n; k++) {
                    if (i >> k & 1) curr = max(curr, nums[j][k]);
                }
            }
            upd[curr - 1]++;
        }

        return upd;
    }};