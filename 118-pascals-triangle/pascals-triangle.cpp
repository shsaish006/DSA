class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> f(numRows);
        for (int i = 0; i < numRows; ++i) {
            f[i].resize(i + 1);
            f[i][0] = f[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
            }
        }
        return f;
    }
};
