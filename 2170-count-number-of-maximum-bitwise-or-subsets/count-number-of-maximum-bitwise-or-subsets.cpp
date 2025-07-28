class Solution {
public:
    int maxOr = 0;
    int count = 0;

    void dfs(const vector<int>& nums, int index, int currentOr) {
        if (index == nums.size()) {
            if (currentOr == maxOr) {
                count++;
            }
            return;
        }

        // Skip current number
        dfs(nums, index + 1, currentOr);

        // Include current number
        dfs(nums, index + 1, currentOr | nums[index]);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        // Compute the maximum possible OR value
        for (int num : nums) {
            maxOr |= num;
        }

        dfs(nums, 0, 0);
        return count;
    }
};
