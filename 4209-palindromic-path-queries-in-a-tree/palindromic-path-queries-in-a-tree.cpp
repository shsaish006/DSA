
class Solution {
    vector<vector<int>> adj, up;
    vector<int> parent, depth, tin, tout, basePrefix, bit;
    int timer;

    void updateBit(int idx, int delta) {
        while (idx < bit.size()) {
            bit[idx] ^= delta;
            idx += idx & -idx;
        }
    }

    int queryBit(int idx) {
        int result = 0;
        while (idx > 0) {
            result ^= bit[idx];
            idx -= idx & -idx;
        }
        return result;
    }

    int findLCA(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];

        for (int k = (int)up.size() - 1; k >= 0; k--) {
            if ((diff >> k) & 1) u = up[k][u];
        }

        if (u == v) return u;

        for (int k = (int)up.size() - 1; k >= 0; k--) {
            if (up[k][u] != up[k][v]) {
                u = up[k][u];
                v = up[k][v];
            }
        }

        return parent[u];
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        adj.assign(n, {});
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        parent.assign(n, 0);
        depth.assign(n, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);
        basePrefix.assign(n, 0);
        timer = 0;

        basePrefix[0] = 1 << (s[0] - 'a');

        vector<int> st = {0};

        while (!st.empty()) {
            int x = st.back();
            st.pop_back();

            if (x < 0) {
                tout[~x] = timer - 1;
                continue;
            }

            int u = x;
            tin[u] = timer++;
            st.push_back(~u);

            for (int i = (int)adj[u].size() - 1; i >= 0; i--) {
                int v = adj[u][i];

                if (v == parent[u]) continue;

                parent[v] = u;
                depth[v] = depth[u] + 1;
                basePrefix[v] = basePrefix[u] ^ (1 << (s[v] - 'a'));
                st.push_back(v);
            }
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        up.assign(LOG, vector<int>(n));

        for (int i = 0; i < n; i++) {
            up[0][i] = parent[i];
        }

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        bit.assign(n + 2, 0);
        vector<bool> ans;

        for (string& q : queries) {
            stringstream ss(q);
            string op;
            int u, v;
            ss >> op >> u;

            if (op == "update") {
                char c;
                ss >> c;

                int oldMask = 1 << (s[u] - 'a');
                int newMask = 1 << (c - 'a');
                int delta = oldMask ^ newMask;

                updateBit(tin[u] + 1, delta);
                updateBit(tout[u] + 2, delta);

                s[u] = c;
            } else {
                ss >> v;

                int lca = findLCA(u, v);
                int prefixU = basePrefix[u] ^ queryBit(tin[u] + 1);
                int prefixV = basePrefix[v] ^ queryBit(tin[v] + 1);

                int pathMask = prefixU ^ prefixV ^ (1 << (s[lca] - 'a'));

                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }

        return ans;
    }
};