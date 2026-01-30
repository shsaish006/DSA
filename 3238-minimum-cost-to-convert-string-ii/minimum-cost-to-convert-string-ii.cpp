class Node {
public:
    Node* ch[26];
    int id;
    Node() {
        memset(ch, 0, sizeof(ch));
        id = -1;
    }
};

class Solution {
    static constexpr long long INF = 4e18;
    Node* root = new Node();
    vector<vector<long long>> dist;
    string s, t;
    vector<long long> dp;
    int idx = 0;

public:
    long long minimumCost(string source, string target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {
        s = source;
        t = target;

        for (auto &w : original) insert(w);
        for (auto &w : changed) insert(w);

        dist.assign(idx, vector<long long>(idx, INF));
        for (int i = 0; i < idx; i++) dist[i][i] = 0;

        for (int i = 0; i < cost.size(); i++) {
            int u = getId(original[i]);
            int v = getId(changed[i]);
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for (int k = 0; k < idx; k++)
            for (int i = 0; i < idx; i++)
                if (dist[i][k] < INF)
                    for (int j = 0; j < idx; j++)
                        if (dist[k][j] < INF)
                            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        int n = s.size();
        dp.assign(n + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == INF) continue;

            if (s[i] == t[i])
                dp[i + 1] = min(dp[i + 1], dp[i]);

            Node *p = root, *q = root;

            for (int j = i; j < n; j++) {
                int a = s[j] - 'a';
                int b = t[j] - 'a';

                if (!p->ch[a] || !q->ch[b]) break;

                p = p->ch[a];
                q = q->ch[b];

                if (p->id == -1 || q->id == -1) continue;

                long long cst = dist[p->id][q->id];
                if (cst < INF)
                    dp[j + 1] = min(dp[j + 1], dp[i] + cst);
            }
        }

        return dp[n] == INF ? -1 : dp[n];
    }

    int insert(const string &w) {
        Node* p = root;
        for (char c : w) {
            int x = c - 'a';
            if (!p->ch[x]) p->ch[x] = new Node();
            p = p->ch[x];
        }
        if (p->id == -1) p->id = idx++;
        return p->id;
    }

    int getId(const string &w) {
        Node* p = root;
        for (char c : w) p = p->ch[c - 'a'];
        return p->id;
    }};