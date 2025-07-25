class Solution {
public:
    int maxSum(std::vector<int>& nums) {
        int maxElement = *std::max_element(nums.begin(), nums.end());
        if (maxElement <= 0) {
            return maxElement;
        }

        std::unordered_set<int> seen;
        int sum = 0;

        for (int num : nums) {
            if (num > 0 && seen.insert(num).second) {
                sum += num;
            }
        }

        return sum;
    }
};