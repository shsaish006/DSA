class Solution {
public:
    int minimumEffort(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(), [&](auto &a, auto &b) {
            return a[1] - a[0] > b[1] - b[0];
        });
        int a = 0, b = 0;
        for (auto &c : nums) {
            if (a < c[1]) {
                b += c[1] - a;
                a = c[1];
            }
            a -= c[0];
         }
         return b;
    }
};