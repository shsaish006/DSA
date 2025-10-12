using ll = long long;
const int mod = 1e9+7;
ll pwr(ll a,ll b){ll r=1%mod;while(b){if(b&1)r=r*a%mod;a=a*a%mod;b>>=1;}return r;}
class Solution {
public:
    int magicalSum(int a, int b, vector<int>& c) {
        int d = c.size(), e = d + 6;
        vector<vector<ll>> f(d, vector<ll>(a+1,1));
        for(int i=0;i<d;i++) for(int j=1;j<=a;j++) f[i][j]=f[i][j-1]*(c[i]%mod)%mod;
        vector<ll> g(a+1,1), h(a+1,1);
        for(int i=1;i<=a;i++) g[i]=g[i-1]*i%mod;
        h[a]=pwr(g[a],mod-2);
        for(int i=a;i>0;i--) h[i-1]=h[i]*i%mod;
        int idx1=a, idx2=a, cnt=a;
        vector<vector<vector<ll>>> s(idx1+1, vector<vector<ll>>(idx2+1, vector<ll>(cnt+1,0)));
        s[0][0][0]=1;
        for(int i=0;i<e;i++){
            vector<vector<vector<ll>>> o(idx1+1, vector<vector<ll>>(idx2+1, vector<ll>(cnt+1,0)));
            for(int j=0;j<=idx1;j++){
                for(int k=0;k<=idx2;k++){
                    for(int l=0;l<=cnt;l++){
                        ll val=s[j][k][l];
                        if(!val) continue;
                        if(i<d){
                            for(int m=0;m+j<=idx1;m++){
                                int n=m+k;
                                int q=n&1;
                                int r=n>>1;
                                int u=j+m;
                                int v=l+q;
                                if(r>idx2||v>cnt) continue;
                                ll w=val*f[i][m]%mod*h[m]%mod;
                                o[u][r][v]+=w;
                                if(o[u][r][v]>=mod) o[u][r][v]-=mod;
                            }
                        } else {
                            int n=k;
                            int q=n&1;
                            int r=n>>1;
                            int u=j;
                            int v=l+q;
                            if(r>idx2||v>cnt) continue;
                            o[u][r][v]+=val;
                            if(o[u][r][v]>=mod) o[u][r][v]-=mod;
                        }
                    }
                }
            }
            s.swap(o);
        }
        ll ans=s[a][0][b]%mod;
        ans=ans*g[a]%mod;
        return (int)ans;
    }
};
