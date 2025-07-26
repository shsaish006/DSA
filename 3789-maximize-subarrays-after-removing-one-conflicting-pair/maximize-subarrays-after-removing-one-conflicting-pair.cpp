class Solution {
public:
    long long maxSubarrays(int n, std::vector<std::vector<int>>& p) {
        std::vector<std::vector<std::pair<int, int>>> a(n + 1);
        for (int i = 0; i < p.size(); ++i) {
            int b = std::min(p[i][0], p[i][1]);
            int c = std::max(p[i][0], p[i][1]);
            a[b].push_back({c - 1, i});
        }

        std::vector<int> d(n + 1), e(n + 1), f(n + 1), g(n + 1);
        std::multiset<std::pair<int, int>> h;
        long long x = 0;

        for (int i = n; i >= 1; --i) {
            for (auto& j : a[i]) h.insert(j);

            if (h.empty()) {
                d[i] = n;
                f[i] = -1;
                e[i] = n;
                g[i] = -1;
            } else {
                d[i] = h.begin()->first;
                f[i] = h.begin()->second;

                if (h.size() >= 2) {
                    auto it = h.begin();
                    std::advance(it, 1);
                    e[i] = it->first;
                    g[i] = it->second;
                } else {
                    e[i] = n;
                    g[i] = -1;
                }
            }
            x += d[i];
        }

        long long y = x - 1LL * n * (n + 1) / 2 + n;
        std::vector<long long> z(p.size(), 0);

        for (int i = 1; i <= n; ++i) {
            if (f[i] != -1) {
                z[f[i]] += (e[i] - d[i]);
            }
        }

        long long r = 0;
        for (long long i : z) r = std::max(r, i);
        return y + r;
    }
};

