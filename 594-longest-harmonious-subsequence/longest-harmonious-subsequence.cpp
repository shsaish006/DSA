class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = 0, ans = 0;
        
        while (right < nums.size()) {
            while (nums[right] - nums[left] > 1) {
                ++left;
            }
            if (nums[right] - nums[left] == 1) {
                ans = max(ans, right - left + 1);
            }
            ++right;
        }
        return ans;
    }
};
