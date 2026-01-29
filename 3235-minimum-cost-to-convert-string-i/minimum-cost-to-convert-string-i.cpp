class Solution {
public:
    long long minimumCost(string s, string t, vector<char>& a, vector<char>& b, vector<int>& c) {
        vector<vector<pair<int,int>>> g(26);
        for (int i = 0; i < a.size(); ++i) {
            g[a[i]-'a'].push_back({b[i]-'a', c[i]});
        }

        const long long inf = 1e18;
        vector<vector<long long>> d(26, vector<long long>(26, inf));

        for (int i = 0; i < 26; ++i) {
            priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
            d[i][i] = 0;
            pq.push({0, i});
            while (!pq.empty()) {
                auto cur = pq.top();
                pq.pop();
                long long dist = cur.first;
                int u = cur.second;
                if (dist > d[i][u]) continue;
                for (auto &p : g[u]) {
                    int v = p.first;
                    long long w = p.second;
                    if (d[i][v] > dist + w) {
                        d[i][v] = dist + w;
                        pq.push({d[i][v], v});
                    }
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != t[i]) {
                long long val = d[s[i]-'a'][t[i]-'a'];
                if (val >= inf) return -1;
                ans += val;
            }
        }
        return ans;
    }};