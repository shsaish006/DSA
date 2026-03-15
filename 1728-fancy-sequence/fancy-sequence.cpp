class Fancy {
public:
    const long long MOD=1000000007;
    vector<long long> nums;
    long long a=1,b=0;

    long long p(long long a,long long b){
        long long c=1;
        while(b){
            if(b&1)c=c*a%MOD;
            a=a*a%MOD;
            b>>=1;
        }
        return c;
    }

    Fancy(){}

    void append(int val){
        long long c=p(a,MOD-2);
        nums.push_back((val-b+MOD)%MOD*c%MOD);
    }

    void addAll(int inc){
        b=(b+inc)%MOD;
    }

    void multAll(int m){
        a=a*m%MOD;
        b=b*m%MOD;
    }

    int getIndex(int idx){
        if(idx>=nums.size()) return -1;
        return (nums[idx]*a+b)%MOD;
    }
};