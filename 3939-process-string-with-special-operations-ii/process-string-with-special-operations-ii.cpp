class Solution {
public:
    char processStr(string s, long long k) {
        long long m = 0;
        for (char c : s)
            m += (c >= 'a' && c <= 'z'), m -= (c == '*') && (m > 0), m *= (c == '#') ? 2 : 1;
        if (k >= m) return '.';
        for (int i = (int)s.size() - 1; i >= 0; i--) {
            char c = s[i];
            m += (c == '*');
            if (c == '#') {
                long long half = m / 2;
                if (k >= half) k -= half;
                m = half;
            }
            if (c == '%') k = m - 1 - k;
            if (c >= 'a' && c <= 'z') {
                if (--m == k) return c;
            }
        }
        return '.';
    }
};