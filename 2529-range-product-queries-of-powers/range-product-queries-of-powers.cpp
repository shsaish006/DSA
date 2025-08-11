class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int mod = 1e9 + 7;
        vector<int> p;
        while (n) {
            p.push_back(n & -n);
            n -= n & -n;
        }
        int m = p.size();
        vector<long long> pre(m + 1, 1);
        for (int i = 0; i < m; ++i) pre[i + 1] = pre[i] * p[i] % mod;
        vector<int> res;
        for (auto &q : queries)
            res.push_back(pre[q[1] + 1] * powmod(pre[q[0]], mod - 2, mod) % mod);
        return res;
    }
private:
    long long powmod(long long a, long long b, int mod) {
        long long r = 1;
        while (b) {
            if (b & 1) r = r * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return r;
    }
};
