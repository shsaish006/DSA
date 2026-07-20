class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), sz = m * n;
        vector<int> a(sz);
        for (int i = 0; i < sz; i++)
            a[(i + k) % sz] = grid[i / n][i % n];

        for (int i = 0; i < sz; i++)
            grid[i / n][i % n] = a[i];

        return grid;
    }
};