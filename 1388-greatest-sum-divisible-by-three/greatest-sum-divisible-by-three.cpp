class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        const int inf = -1e9;
        vector<int> dp(3, inf);
        dp[0] = 0;

        for(int x : nums) {
            vector<int> temp = dp;
            for(int j = 0; j < 3; j++) {
                int nxt = (j + x) % 3;
                temp[nxt] = max(temp[nxt], dp[j] + x);
            }
            dp = temp;
        }
        return dp[0];
    }
};