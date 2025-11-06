class UnionFind {
public:
    vector<int> p, sz;
    
    UnionFind(int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }
    
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        UnionFind uf(c + 1);
        for (auto& e : connections) uf.unite(e[0], e[1]);

        vector<set<int>> st(c + 1);
        for (int i = 1; i <= c; ++i) st[uf.find(i)].insert(i);

        vector<int> ans;
        for (auto& q : queries) {
            int type = q[0], x = q[1];
            int root = uf.find(x);
            if (type == 1) {
                if (st[root].count(x)) ans.push_back(x);
                else if (!st[root].empty()) ans.push_back(*st[root].begin());
                else ans.push_back(-1);
            } else {
                st[root].erase(x);
            }
        }
        return ans;
    }
};