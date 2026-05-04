class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long a=0, b=sqrt(c); a<=b;)
        if(a*a+b*b<c) a++;
        else if (a*a+b*b>c) b--;
        else return 1;
        return 0;
        
    }
};