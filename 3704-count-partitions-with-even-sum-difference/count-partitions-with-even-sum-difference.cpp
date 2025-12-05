class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0, ans = 0;
        
        for (int i = 0; i < n - 1; ++i) {
            leftSum += nums[i];
            int rightSum = total - leftSum;
            if ((leftSum - rightSum) % 2 == 0) {
                ans++;
            }
        }
        
        return ans;
    }
};