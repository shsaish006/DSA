#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
ll modpow(ll a,ll e){ll r=1%MOD;while(e){if(e&1)r=r*a%MOD;a=a*a%MOD;e>>=1;}return r;}
class Solution {
public:
    int magicalSum(int m, int k, vector<int>& nums) {
        int n = nums.size();
        int maxPos = n + 6;
        vector<vector<ll>> powv(n, vector<ll>(m+1,1));
        for(int i=0;i<n;i++) for(int t=1;t<=m;t++) powv[i][t] = powv[i][t-1] * (nums[i]%MOD) % MOD;
        vector<ll> fact(m+1,1), invfact(m+1,1);
        for(int i=1;i<=m;i++) fact[i]=fact[i-1]*i%MOD;
        invfact[m]=modpow(fact[m], MOD-2);
        for(int i=m;i>0;i--) invfact[i-1]=invfact[i]*i%MOD;
        int U = m, C = m, O = m;
        vector<vector<vector<ll>>> dp(U+1, vector<vector<ll>>(C+1, vector<ll>(O+1,0)));
        dp[0][0][0]=1;
        for(int pos=0; pos<maxPos; pos++){
            vector<vector<vector<ll>>> ndp(U+1, vector<vector<ll>>(C+1, vector<ll>(O+1,0)));
            for(int used=0; used<=U; used++){
                for(int carry=0; carry<=C; carry++){
                    for(int ones=0; ones<=O; ones++){
                        ll cur = dp[used][carry][ones];
                        if(!cur) continue;
                        if(pos < n){
                            for(int take=0; take+used<=U; take++){
                                int s = take + carry;
                                int bit = s&1;
                                int nc = s>>1;
                                int nou = used + take;
                                int non = ones + bit;
                                if(nc > C || non > O) continue;
                                ll add = cur * powv[pos][take] % MOD * invfact[take] % MOD;
                                ndp[nou][nc][non] += add;
                                if(ndp[nou][nc][non] >= MOD) ndp[nou][nc][non]-=MOD;
                            }
                        } else {
                            int s = carry;
                            int bit = s&1;
                            int nc = s>>1;
                            int nou = used;
                            int non = ones + bit;
                            if(nc > C || non > O) continue;
                            ndp[nou][nc][non] += cur;
                            if(ndp[nou][nc][non] >= MOD) ndp[nou][nc][non]-=MOD;
                        }
                    }
                }
            }
            dp.swap(ndp);
        }
        ll res = dp[m][0][k] % MOD;
        res = res * fact[m] % MOD;
        return (int)res;
    }

    
};
