class Solution {
public:
int mod=1e9+7;
vector<vector<vector<int>>> dp;
int dfs(int i, int a, int b, vector<int> &v){
    if(i==v.size()) return a==b;
    int &x = dp[i][a][b];
    if(x!=-1) return x;
    return x =((dfs(i+1,a,b,v)+dfs(i+1,gcd(a,v[i]), b, v))%mod+ dfs(i+1,a,gcd(b,v[i]),v))%mod;
}

    int subsequencePairCount(vector<int>& nums) {
        int m=*max_element(nums.begin(), nums.end());
        dp.assign(nums.size(),vector<vector<int>>(m+1, vector<int> (m+1,-1)));
        return (dfs(0,0,0,nums)-1+mod)%mod;
        
    }
};
