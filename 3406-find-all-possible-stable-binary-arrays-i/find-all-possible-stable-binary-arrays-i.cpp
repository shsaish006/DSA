class Solution {
public:
    int numberOfStableArrays(int a,int b,int c) {
        int mod=1e9+7;
        vector f(a+1,vector<array<long long,2>>(b+1,{-1,-1}));
        
        auto dfs=[&](auto&& dfs,int i,int j,int k)->long long{
            if(i<0||j<0) return 0;
            if(!i) return k&&j<=c;
            if(!j) return !k&&i<=c;
            auto &v=f[i][j][k];
            if(v!=-1) return v;
            if(!k) v=(dfs(dfs,i-1,j,0)+dfs(dfs,i-1,j,1)-dfs(dfs,i-c-1,j,1)+mod)%mod;
            else v=(dfs(dfs,i,j-1,0)+dfs(dfs,i,j-1,1)-dfs(dfs,i,j-c-1,0)+mod)%mod;
            return v;
        };
        
        return (dfs(dfs,a,b,0)+dfs(dfs,a,b,1))%mod;
    }
};
//  Cp