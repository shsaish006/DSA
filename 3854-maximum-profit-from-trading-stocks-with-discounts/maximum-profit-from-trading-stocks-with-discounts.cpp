class Solution {
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        vector<vector<int>> g(n + 1);
        for (auto &e : hierarchy) g[e[0]].push_back(e[1]);

        function<vector<array<int,2>>(int)> dfs = [&](int u) {
            vector<array<int,2>> nxt(budget + 1, {0, 0});

            for (int v : g[u]) {
                auto fv = dfs(v);
                for (int j = budget; j >= 0; j--) {
                    for (int jv = 0; jv <= j; jv++) {
                        for (int p = 0; p < 2; p++) {
                            nxt[j][p] = max(nxt[j][p], nxt[j - jv][p] + fv[jv][p]);
                        }
                    }
                }
            }

            vector<array<int,2>> f(budget + 1, {0, 0});
            int price = future[u - 1];

            for (int j = 0; j <= budget; j++) {
                for (int p = 0; p < 2; p++) {
                    int cost = present[u - 1] / (p + 1);
                    if (j >= cost)
                        f[j][p] = max(nxt[j][0], nxt[j - cost][1] + price - cost);
                    else
                        f[j][p] = nxt[j][0];
                }
            }
            return f;
        };

        return dfs(1)[budget][0];
    }
};