class Solution {
public:
    int countSubmatrices(vector<vector<int>>& nums, int k) {
        int m = nums.size(), n = nums[0].size();
        vector<vector<int>> s(m + 1, vector<int>(n + 1, 0));
        int cnt = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + nums[i-1][j-1];
                if (s[i][j] <= k) cnt++;
            }
        }
        return cnt;
    }
};