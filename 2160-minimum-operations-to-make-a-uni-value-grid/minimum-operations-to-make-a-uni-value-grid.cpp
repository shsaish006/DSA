class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int a = grid[0][0] % x;
        for (auto &b : grid) {
            for (int c : b) {
                if (c % x != a) return -1;
                nums.push_back(c);
            }
        }
        sort(nums.begin(), nums.end());
        int d = nums[nums.size() / 2];
        int cnt = 0;
        for (int c : nums) {
            cnt += abs(c - d) / x;
        }
        

        return cnt;
    }
};