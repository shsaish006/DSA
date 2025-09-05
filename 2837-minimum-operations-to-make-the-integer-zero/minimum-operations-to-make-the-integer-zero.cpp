class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        using ll = long long;
        for (ll k = 1; ; k++) {
            ll rem = num1 - (ll)k * num2;
            if (rem < 0) return -1;
            int bits = __builtin_popcountll(rem);
            if (bits <= k && k <= rem) return k;
        }
    }
};

