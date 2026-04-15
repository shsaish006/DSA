class Solution {
public:
    int closestTarget(vector<string>& a, string b, int c) {
        int n=a.size(),l=c,r=c;
        for(int d=0;d<n;d++){
            if(a[l]==b || a[r]==b) return d;
            l=(l-1+n)%n;
            r=(r+1)%n;
        }
        return -1;
    }
};