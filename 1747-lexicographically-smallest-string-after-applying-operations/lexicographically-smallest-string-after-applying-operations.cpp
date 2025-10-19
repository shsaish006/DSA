class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        string o = s, t;
        queue<string> q;
        unordered_set<string> vis;
        q.push(s);
        vis.insert(s);
        int n = s.size();
        while (!q.empty()) {
            s = q.front();
            q.pop();
            o = min(o, s);
            t = s;
            for (int i = 1; i < n; i += 2) t[i] = (t[i] - '0' + a) % 10 + '0';
            if (!vis.count(t)) {
                vis.insert(t);
                q.push(t);
            }
            t = s.substr(n - b) + s.substr(0, n - b);
            if (!vis.count(t)) {
                vis.insert(t);
                q.push(t);
            }
        }
        return o;
    }
};
