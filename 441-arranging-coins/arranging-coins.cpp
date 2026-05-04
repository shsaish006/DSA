class Solution {
public:
    int arrangeCoins(int n) {
        long long a=1, b=n;
        while(a<b){
            long long c=(a+b+1)/2;
            if(c*(c+1)/2>n) b=c-1;
            else a=c;
        }
        return a;
        }
};