class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp = energy; 
        int ans = INT_MIN;

        for (int i = n - k - 1; i >= 0; --i)
            dp[i] += dp[i + k]; 

        for (int val : dp)
            ans = max(ans, val);

        return ans;
    }
};
