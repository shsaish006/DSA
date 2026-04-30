class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector dp(m,vector(n,vector<int>(k+1,-1e9)));
        dp[0][0][k]=0;

        for(int sum=0;sum<m+n-1;sum++){
            for(int i=0;i<m;i++){
                int j=sum-i;
                if(j<0||j>=n) continue;
                for(int t=0;t<=k;t++){
                    if(dp[i][j][t]<0) continue;
                    if(i+1<m){
                        int nt=t-(grid[i+1][j]>0);
                        if(nt>=0)
                            dp[i+1][j][nt]=max(dp[i+1][j][nt],dp[i][j][t]+grid[i+1][j]);
                    }
                    if(j+1<n){
                        int nt=t-(grid[i][j+1]>0);
                        if(nt>=0)
                            dp[i][j+1][nt]=max(dp[i][j+1][nt],dp[i][j][t]+grid[i][j+1]);
                    }
                }
            }
        }

        int ans=*max_element(dp[m-1][n-1].begin(),dp[m-1][n-1].end());
        return ans<0?-1:ans;
    }
};