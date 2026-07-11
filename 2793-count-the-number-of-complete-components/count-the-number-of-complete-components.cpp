class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& e) {
        vector<vector<int>> g(n);
        for (auto &i : e) g[i[0]].push_back(i[1]), g[i[1]].push_back(i[0]);
        vector<int> vis(n);
        auto dfs = [&](auto &&self, int i, int &v, int &d) -> void {
            vis[i] = 1;
            v++;
            d += g[i].size();
            for (int j : g[i]) if (!vis[j]) self(self, j, v, d);
        };
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int v = 0, d = 0;
                dfs(dfs, i, v, d);
                ans += v * (v - 1) == d;
            }
        }
        return ans;
    }
};