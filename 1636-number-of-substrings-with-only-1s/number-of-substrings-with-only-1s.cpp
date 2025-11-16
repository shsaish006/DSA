class Solution {
public:
    int numSub(string s) {
        int mod = 1000000007;
        int a = 0, b = 0;
        for(char c : s) {
            if(c == '0') b = 0;
            else {
                b++;
                a = (a + b) % mod;
            }
        }
        return a;
    }
};