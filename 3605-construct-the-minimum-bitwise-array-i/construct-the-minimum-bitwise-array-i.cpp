class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int a : nums) {
            if (a == 2) {
                ans.push_back(-1);
                continue;
            }
            int b = a;
            int c = 0;
            while (b & 1) {
                b >>= 1;
                c++;
            }
            ans.push_back(a ^ (1 << (c - 1)));
        }
        return ans;
    }
};