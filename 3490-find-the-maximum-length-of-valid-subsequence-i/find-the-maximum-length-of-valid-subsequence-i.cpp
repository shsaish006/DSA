class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int k = 2;
        int dp[2][2] = {};
        int maxLen = 0;

        for (int num : nums) {
            int rem = num % k;

            for (int prevRem = 0; prevRem < k; ++prevRem) {
                int expectedPrev = (prevRem - rem + k) % k;
                dp[rem][expectedPrev] = dp[expectedPrev][rem] + 1;
                maxLen = max(maxLen, dp[rem][expectedPrev]);
            }
        }

        return maxLen;
    }
};
