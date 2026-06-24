class Solution {
    static const int mod = 1e9 + 7;

    using M = vector<vector<long long>>;

    M mul(M &a, M &b) {
        int n = a.size();
        M c(n, vector<long long>(n));

        for (int i = 0; i < n; i++)
            for (int k = 0; k < n; k++)
                if (a[i][k])
                    for (int j = 0; j < n; j++)
                        c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;

        return c;
    }

    M power(M a, long long p) {
        int n = a.size();
        M r(n, vector<long long>(n));

        for (int i = 0; i < n; i++) r[i][i] = 1;

        while (p) {
            if (p & 1) r = mul(r, a);
            a = mul(a, a);
            p >>= 1;
        }

        return r;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if (n == 1) return m;

        int sz = 2 * m;
        M t(sz, vector<long long>(sz));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++)
                t[i][j + m] = 1;

            for (int j = i + 1; j < m; j++)
                t[i + m][j] = 1;
        }

        t = power(t, n - 1);
        long long ans = 0;

        for (int i = 0; i < sz; i++)
            for (int j = 0; j < sz; j++)
                ans = (ans + t[i][j]) % mod;
        return ans;
    }
};
//  copy pasted i 