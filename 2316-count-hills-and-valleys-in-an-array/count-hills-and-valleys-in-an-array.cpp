class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int a = 0, b = nums.size();
        for (int c = 1; c < b - 1; ++c) {
            if (nums[c] == nums[c - 1]) continue;
            int d = c - 1;
            while (d >= 0 && nums[d] == nums[c]) --d;
            int e = c + 1;
            while (e < b && nums[e] == nums[c]) ++e;
            if (d >= 0 && e < b) {
                if ((nums[c] > nums[d] && nums[c] > nums[e]) || (nums[c] < nums[d] && nums[c] < nums[e])) {
                    ++a;
                }
            }
        }
        return a;
        
    }
};
