class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), [](auto &x, auto &y){
            if (x[0] == y[0]) return x[1] > y[1];
            return x[0]< y[0];
        });
        int n = a.size(), ans = n;
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (a[j][0] <= a[i][0] && a[j][1] >= a[i][1]) {
                    dp[i] = 1;
                    break;
                }

            }
            ans -= dp[i];
        }
        return ans;
    }
};