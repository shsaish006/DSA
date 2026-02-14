class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row+1, vector<double>(query_row+1,0.0));
        dp[0][0]=poured;
        for(int i=1;i<=query_row;++i){
            for(int j=0;j<=i;++j){
                double left=0.0, right=0.0;
                if(j-1>=0)
                    left=max(0.0,(dp[i-1][j-1]-1.0)/2.0);
                
                if(j<=i-1)
                    right=max(0.0,(dp[i-1][j]-1.0)/2.0);
                dp[i][j]=left+right;
            }
        }
        return min(1.0,dp[query_row][query_glass]);
        
    }
};