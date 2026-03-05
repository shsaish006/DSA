class Solution {
public:
    int minOperations(string s) {
        int c=0,n=s.size();
        for(int i=0;i<n;i++) if((s[i]-'0')!=i%2) c++;
        return min(c,n-c);
    }
};