class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int a=dungeon.size(), b=dungeon[0].size();
        vector<vector<int>> dp(a,vector<int>(b,0));
        dp[a-1][b-1]=max(1,1-dungeon[a-1][b-1]);

        for(int i=a-2;i>=0;i--)
        dp[i][b-1]=max(1,dp[i+1][b-1]-dungeon[i][b-1]);

        for(int j=b-2;j>=0;j--)
        dp[a-1][j]=max(1,dp[a-1][j+1]-dungeon[a-1][j]);

        for(int i=a-2;i>=0;i--){
            for(int j=b-2;j>=0;j--){

                int nxt=min(dp[i+1][j],dp[i][j+1]);
                dp[i][j]=max(1,nxt-dungeon[i][j]);
            }
        }
        return dp[0][0];
        
        
    }
};