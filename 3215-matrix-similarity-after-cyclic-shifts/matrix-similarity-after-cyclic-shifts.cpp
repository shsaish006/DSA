class Solution {
public:
    bool areSimilar(vector<vector<int>>& nums, int val) {
        int a = nums.size(), b = nums[0].size();
        val %= b;
        for (int i = 0; i < a; i++) {
            vector<int> vals = nums[i];
            if (i & 1) {
                rotate(vals.begin(), vals.begin() + val, vals.end());
            } else {
                rotate(vals.begin(), vals.end() - val, vals.end());
            }
            if (vals != nums[i]) return false;
        }
        return true;
    }
};