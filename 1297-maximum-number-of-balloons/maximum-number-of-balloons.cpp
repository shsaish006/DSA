class Solution {
public:
    int maxNumberOfBalloons(string s) {
        vector<int> f(26);
        for(char c:s) f[c-'a']++;
        f[11]/=2;
        f[14]/=2;
        return min({f[0],f[1],f[13],f[11], f[14]});

        
    }
};