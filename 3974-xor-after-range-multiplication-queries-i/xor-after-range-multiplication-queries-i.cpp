class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int d = 1000000007, o = 0;
        for (auto &a : queries) {
            int b = a[0], c = a[1], s = a[2], val = a[3];
            while (b <= c) {
                nums[b] = 1LL * nums[b] * val % d;
                b += s;
            }
        }
        for (int a : nums) o ^= a;
        return o;
    }
};