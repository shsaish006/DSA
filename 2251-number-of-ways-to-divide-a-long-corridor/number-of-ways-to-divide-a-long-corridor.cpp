class Solution {
public:
    int numberOfWays(string corridor) {
        const int mod = 1000000007;
        long long o = 0;
        long long cnt = 0;
        long long val = 1;
        bool s = false;
        for (char c : corridor) {
            if (c == 'S') {
                o++;
                if (o == 2) {
                    s = true;
                } else if (o == 3) {
                    val = (val * (cnt + 1)) % mod;
                    cnt = 0;
                    o = 1;
                }
            } else {
                if (o == 2) cnt++;
            }
        }
        if (!s || o != 2) return 0;
        return (int)val;
    }
};


