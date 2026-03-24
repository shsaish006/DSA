class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int a = grid.size(), b = grid[0].size(), val = 12345;
        vector<int> nums;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) nums.push_back(grid[i][j] % val);
        }
        int cnt = nums.size();
        vector<int> nxt(cnt, 1), upd(cnt, 1);
        for (int i = 1; i < cnt; i++) upd[i] = 1LL * upd[i - 1] * nums[i - 1] % val;
        for (int i = cnt - 2; i >= 0; i--) nxt[i] = 1LL * nxt[i + 1] * nums[i + 1] % val;
        vector<vector<int>> ans(a, vector<int>(b));
        for (int i = 0, idx = 0; i < a; i++) {
            for (int j = 0; j < b; j++, idx++) {
                ans[i][j] = 1LL * upd[idx] * nxt[idx] % val;
            }
        }
        return ans;
    }
};