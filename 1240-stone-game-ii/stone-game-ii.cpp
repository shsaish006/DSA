class Solution {
public:
//  piles=a 
    int stoneGameII(vector<int>& a) {
        int n=a.size();
        vector<int> s(n+1);
        for(int i=n-1;i>=0;i--) s[i]=s[i+1]+ a[i];
        vector<vector<int>> dp(n+1, vector<int> (n+1));
        for(int i=n-1;i>=0;i--)
        for(int m=n;m>=1;m--){
        if(i+2*m>=n) dp[i][m]=s[i];
        else 
            for(int x=1;x<=2*m;x++)
            dp[i][m]= max(dp[i][m], s[i]-dp[i+x][max(m,x)]);
    }
    return dp[0][1];

        
    }
};
// player hardum piles collect karenge front se
//  M can only same or increase
//  a larger m matlab jyada piles
//  optimally har move best hoga dono ka 
//  1<= X<=2*M  evry posiible choice hoga 
