class Solution {
public:
    static const int mod = 1000000007;
    vector<vector<int>> g;

    long long pw(long long a, long long n) {
        long long r = 1;
        while (n) {
            if (n & 1) r = r * a % mod;
            a = a * a % mod;
            n >>= 1;
        }
        return r;
    }

    int dfs(int u, int p) {
        int mx = 0;
        for (int v : g[u]) {
            if (v == p) continue;
            mx = max(mx, 1 + dfs(v, u));
        }
        return mx;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        g.assign(n + 1, {});

        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        int h = dfs(1, 0);
        return pw(2, h - 1);
    }
};