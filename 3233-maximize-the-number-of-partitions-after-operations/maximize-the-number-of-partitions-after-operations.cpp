class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        int a = s.size();
        unordered_map<long long, int> o;
        function<int(int, int, int)> f = [&](int b, int c, int d) {
            if (b >= a) return 1;
            long long e = (long long)b << 32 | c << 1 | d;
            if (o.count(e)) return o[e];
            int g = 1 << (s[b] - 'a');
            int h = c | g;
            int i = __builtin_popcount(h) > k ? f(b + 1, g, d) + 1 : f(b + 1, h, d);
            if (d) {
                for (int j = 0; j < 26; j++) {
                    h = c | (1 << j);
                    if (__builtin_popcount(h) > k) i = max(i, f(b + 1, 1 << j, 0) + 1);
                    else i = max(i, f(b + 1, h, 0));
                }
            }
            return o[e] = i;
        };

        
        return f(0, 0, 1);
    }
};