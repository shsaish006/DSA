class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> g(n + 1);
        for (auto x : roads) {
            g[x[0]].push_back({x[1], x[2]});
            g[x[1]].push_back({x[0], x[2]});
        }
        queue<int> q;
        vector<int> vis(n + 1);
        q.push(1);
        vis[1] = 1;
        int ans = INT_MAX;
        while (!q.empty()) {
            int a = q.front();
            q.pop();
            for (auto x : g[a]) {
                ans = min(ans, x.second);
                if (!vis[x.first]) {
                    vis[x.first] = 1;
                    q.push(x.first);
                }
            }
        }

        return ans;
    }
};