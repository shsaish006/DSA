class Solution {
public:
    int findMaxForm(vector<string>& a, int m, int n) {
        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        for (auto &s : a) {
            int x = 0, y = 0;
            for (auto c : s) (c == '0' ? x : y)++;
            for (int i = m; i >= x; i--) {
                for (int j = n; j >= y; j--) {
                    f[i][j] = max(f[i][j], f[i - x][j - y] + 1);
                }
            }
        }
        return f[m][n];
    }};