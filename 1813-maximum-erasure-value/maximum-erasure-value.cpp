class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int left = 0, right = 0, sum = 0, maxSum = 0;
        while (right < nums.size()) {
            while (seen.count(nums[right])) {
                seen.erase(nums[left]);
                sum -= nums[left++];
            }
            seen.insert(nums[right]);
            sum += nums[right++];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};
