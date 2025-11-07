class Solution {
public:
    long long maxPower(vector<int>& a, int r, int k) {
        int n = a.size();
        vector<long long> d(n + 2), s(n + 2);
        for (int i = 0; i < n; i++) {
            int l = max(0, i - r), rr = min(n, i + r + 1);
            d[l] += a[i];
            d[rr] -= a[i];
        }
        for (int i = 0; i < n; i++) s[i + 1] = s[i] + d[i];
        auto ok = [&](long long x) {
            vector<long long> diff(n + 2);
            long long t = 0, kk = k;
            for (int i = 0; i < n; i++) {
                t += diff[i];
                long long need = x - (s[i + 1] + t);
                if (need > 0) {
                    if (kk < need) return false;
                    kk -= need;
                    t += need;
                    int rr = min(n, i + 2 * r + 1);
                    diff[rr] -= need;
                }
            }
            return true;
        };
        long long l = 0, rr = 1e12;
        while (l < rr) {
            long long m = (l + rr + 1) / 2;
            if (ok(m)) l = m; else rr = m - 1;
        }
        return l;
    }
};