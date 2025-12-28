class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            int l = 0, r = n - 1, pos = n;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (grid[i][mid] < 0) {
                    pos = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            ans += n - pos;} return ans; }};