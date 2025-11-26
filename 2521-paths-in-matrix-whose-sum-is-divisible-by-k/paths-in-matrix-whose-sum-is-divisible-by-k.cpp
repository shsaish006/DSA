class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int K) {
        int mod = 1000000007;
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(K, 0)));
        
        dp[0][0][grid[0][0] % K] = 1;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) continue;
                for(int k = 0; k < K; k++) dp[i % 2][j][k] = 0;
                
                for(int k = 0; k < K; k++) {
                    int curr = (k - grid[i][j] % K + K) % K;
                    
                    if(i > 0)
                        dp[i % 2][j][k] = (dp[i % 2][j][k] + dp[(i - 1) % 2][j][curr]) % mod;
                    
                    if(j > 0)
                        dp[i % 2][j][k] = (dp[i % 2][j][k] + dp[i % 2][j - 1][curr]) % mod;
                }
            }
        }
        
        return dp[(m - 1) % 2][n - 1][0];
    }
};