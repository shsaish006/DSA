// class Solution {
// public:
//     int maximumAmount(vector<vector<int>>& coins) {
//         int m = coins.size(), n = coins[0].size();
//         vector<vector<vector<int>>> f(m, vector<vector<int>>(n, vector<int>(3, -1)));
//         auto dfs = [&](this auto&& dfs, int i, int j, int k) -> int {
//             if (i >= m || j >= n) {
//                 return INT_MIN / 2;
//             }
//             if (f[i][j][k] != -1) {
//                 return f[i][j][k];
//             }
//             if (i == m - 1 && j == n - 1) {
//                 return k > 0 ? max(0, coins[i][j]) : coins[i][j];
//             }
//             int ans = coins[i][j] + max(dfs(i + 1, j, k), dfs(i, j + 1, k));
//             if (coins[i][j] < 0 && k > 0) {
//                 ans = max({ans, dfs(i + 1, j, k - 1), dfs(i, j + 1, k - 1)});
//             }
//             return f[i][j][k] = ans;
//         };
//         return dfs(0, 0, 2); }};






static int dp[500][3];

class Solution {
public:
    static int maximumAmount(vector<vector<int>>& coins) {
        const int r=coins.size(), c=coins[0].size();
        // Base case
        int x=coins[0][0];
        dp[0][0]=x;          
        dp[0][1]=dp[0][2]=max(0, x);  

        for(int j=1; j<c; j++){// 0th row
            x=coins[0][j];
            for (int k=2; k>0; k--){
                dp[j][k]=max(x+dp[j-1][k], dp[j-1][k-1]);
            }
            dp[j][0]=x+dp[j-1][0];// k=0
        }

        for (int i=1; i<r; i++) {
            // 0th col
            x=coins[i][0];
            for (int k=2; k>0; k--){
                dp[0][k]=max(x+dp[0][k], dp[0][k-1]);
            }
            dp[0][0]=x+dp[0][0];// k=0
            
            for (int j=1; j<c; j++) {
                x=coins[i][j];
                for (int k=2; k>0; k--) {
                    dp[j][k]=max(max(x+dp[j-1][k], dp[j-1][k-1]), max(x+dp[j][k], dp[j][k-1]));
                }
                dp[j][0]=x+max(dp[j][0], dp[j-1][0]);// k=0

            }
        }
        return dp[c-1][2];
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();