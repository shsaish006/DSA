class Solution {
public:
    long long gcdSum(vector<int>& a) {
        int n=a.size(),b=0;
        vector<int> c;
        for(int d:a)
        {
            b=max(b,d);
            c.push_back(gcd(b,d));
        }
        sort(c.begin(),c.end());
        long long s=0;
        for(int i=0;i<n/2;i++)
            s+=gcd(c[i],c[n-i-1]);
            
        return s;
    }
};
