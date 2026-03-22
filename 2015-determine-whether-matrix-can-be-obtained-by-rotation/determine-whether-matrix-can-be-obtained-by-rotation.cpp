class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int k = 0; k < 4; k++) {
            if (mat == target) return true;
            int n = mat.size();
            vector<vector<int>> nums(n, vector<int>(n));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    nums[j][n - 1 - i] = mat[i][j];
                }
            }
            mat = nums;
        }
        return false;
    }
};