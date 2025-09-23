class Solution {
public:
    int distinctEchoSubstrings(string text) {
        auto get=[&](int l, int r, const vector<long long> &h, const vector<long long> &p, long long mod){
            return (h[r]-h[l-1]*p[r-l+1]%mod+mod)%mod;

        };
        int n=text.size();
        long long base=131, mod=1000000007;
        vector<long long> h(n+10,0), p(n+10,1);
        for(int i=0;i<n;i++){
            int  t=text[i]-'a'+1;
            h[i+1]=(h[i]*base%mod+t)%mod;
            p[i+1]=p[i]*base%mod;

        }
        unordered_set<long long> vis;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j+=2){
                int k=(i+j)>>1;
                long long a=get(i+1,k+1,h,p,mod);
                long long b=get(k+2,j+1,h,p,mod);
                if(a==b) vis.insert(a);

            }
        }
        return  vis.size();
        
    }
};