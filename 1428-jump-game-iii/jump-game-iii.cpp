class Solution {
public:
    bool canReach(vector<int>& a, int start) {
        int n = a.size();
        vector<int> vis(n, 0);
        stack<int> s;
        s.push(start);
        vis[start] = 1;

        while (!s.empty()) {
            int idx = s.top();
            s.pop();

            if (a[idx] == 0) return true;

            int val = a[idx];

            int nxt = idx + val;
            if (nxt < n && !vis[nxt]) {
                vis[nxt] = 1;
                s.push(nxt);
            }

            nxt = idx - val;
            if (nxt >= 0 && !vis[nxt]) {
                vis[nxt] = 1;
                s.push(nxt);
            }
        }

        return false;
    }
};