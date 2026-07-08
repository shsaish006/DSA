class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& q) {
        int n = s.size(), mod = 1e9 + 7;
        vector<int> sm(n + 1), c(n + 1);
        vector<long long> p(n + 1), pw(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pw[i] = pw[i - 1] * 10 % mod;
            int d = s[i - 1] - '0';
            sm[i] = sm[i - 1] + d;
            c[i] = c[i - 1] + (d > 0);
            p[i] = (p[i - 1] * (d ? 10 : 1) + d) % mod;
        }

        vector<int> ans;
        for (auto &i : q) {
            int l = i[0], r = i[1];
            ans.push_back((p[r + 1] - p[l] * pw[c[r + 1] - c[l]] % mod + mod) % mod *
                          1LL * (sm[r + 1] - sm[l]) % mod);
        }
        return ans;
    }
};