class Solution {
public:
    int maxScore(vector<int>&a) {
        int n=a.size(), N=1<<n;
        vector<int> dp(N), g(n*n);
        for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        g[i*n+j]=gcd(a[i],a[j]);
        for(int m=0; m<N;m++){
            int c= __builtin_popcount(m);
            if(c&1)continue;
            for(int i=0;i<n;i++) if(m>> i&1)
            for(int j=i+1;j<n;j++) if(m>> j&1)
            dp[m]=max(dp[m], dp[m^(1<<i)^(1<<j)]+c/2*g[i*n+j]);
        }
        return dp[N-1];
    }
};