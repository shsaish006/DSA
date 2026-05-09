class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int a = grid.size(), b = grid[0].size();

        for (int i = 0; i < min(a, b) / 2; i++) {
            vector<pair<int,int>> vals;
            vector<int> nums;

            for (int j = i; j < b - i - 1; j++) vals.push_back({i, j});
            for (int j = i; j < a - i - 1; j++) vals.push_back({j, b - i - 1});
            for (int j = b - i - 1; j > i; j--) vals.push_back({a - i - 1, j});
            for (int j = a - i - 1; j > i; j--) vals.push_back({j, i});

            for (auto &[c, d] : vals) nums.push_back(grid[c][d]);

            int s = nums.size();

            for (int j = 0; j < s; j++) {
                auto [c, d] = vals[j];
                grid[c][d] = nums[(j + k) % s];
            }
        }

        return grid;
    }
};