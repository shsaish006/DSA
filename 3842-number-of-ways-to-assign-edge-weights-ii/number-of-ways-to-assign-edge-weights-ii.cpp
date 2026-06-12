class Solution {
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& e, vector<vector<int>>& q) {
        int n = e.size() + 1, lg = 20;
        vector<vector<int>> g(n + 1), up(n + 1, vector<int>(lg));
        vector<int> d(n + 1);

        for (auto &v : e) {
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }

        auto dfs = [&](auto &&self, int u, int p) -> void {
            up[u][0] = p;
            for (int i = 1; i < lg; i++) up[u][i] = up[up[u][i - 1]][i - 1];
            for (int v : g[u]) {
                if (v == p) continue;
                d[v] = d[u] + 1;
                self(self, v, u);
            }
        };
        dfs(dfs, 1, 0);

        auto lca = [&](int a, int b) {
            if (d[a] < d[b]) swap(a, b);
            int k = d[a] - d[b];
            for (int i = 0; i < lg; i++) if (k >> i & 1) a = up[a][i];
            if (a == b) return a;
            for (int i = lg - 1; i >= 0; i--) {
                if (up[a][i] != up[b][i]) {
                    a = up[a][i];
                    b = up[b][i];
                }
            }
            return up[a][0];
        };

        const int mod = 1e9 + 7;
        vector<int> p(n + 1, 1);
        for (int i = 1; i <= n; i++) p[i] = 2LL * p[i - 1] % mod;

        vector<int> ans;
        for (auto &v : q) {
            int a = v[0], b = v[1];
            if (a == b) ans.push_back(0);
            else {
                int c = lca(a, b);
                int dis = d[a] + d[b] - 2 * d[c];
                ans.push_back(p[dis - 1]);
            }
        }
        return ans;
    }
};