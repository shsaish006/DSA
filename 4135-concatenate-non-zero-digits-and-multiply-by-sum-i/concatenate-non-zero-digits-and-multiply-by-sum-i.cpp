class Solution {
public:
    long long sumAndMultiply(int n) {
        int s=0,x=0,p=1;
        while(n){
            int d=n%10;
            if(d) s+=d,x+=d*p,p*=10;
            n/=10;
        }
        return 1LL*s*x;
    }
};