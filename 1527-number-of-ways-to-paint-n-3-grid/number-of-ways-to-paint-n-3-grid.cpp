class Solution {
public:
    int numOfWays(int n) {
        const int mod=1e9+7;
        long long a=6;
        long long b=6;
        for(int i=2;i<=n;i++){
            long long c=(a*3+b*2)%mod;
            long long d=(a*2+b*2)%mod;
            a=c;
            b=d;
        }
        return (a+b)%mod;
        
    }
};