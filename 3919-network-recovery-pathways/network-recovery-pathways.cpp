class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& e, vector<bool>& on, long long k) {
        int n = on.size(), l = 1e9, r = 0;
        vector<vector<pair<int,int>>> g(n);
        for (auto &x : e) {
            if (!on[x[0]] || !on[x[1]]) continue;
            g[x[0]].push_back({x[1], x[2]});
            l = min(l, x[2]);
            r = max(r, x[2]);
        }
        auto ok = [&](int x) {
            vector<long long> d(n, 4e18);
            priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
            d[0] = 0;
            pq.push({0,0});
            while (!pq.empty()) {
                auto [c,u] = pq.top();
                pq.pop();
                if (c != d[u]) continue;
                for (auto &[v,w] : g[u]) {
                    if (w < x || c + w >= d[v]) continue;
                    d[v] = c + w;
                    pq.push({d[v], v});
                }
            }
            return d[n-1] <= k;
        };
        
        int ans = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (ok(m)) ans = m, l = m + 1;
            else r = m - 1;
        }
        return ans;
    }
};