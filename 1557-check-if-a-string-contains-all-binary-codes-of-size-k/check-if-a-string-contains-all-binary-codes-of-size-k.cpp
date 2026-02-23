class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        int m = 1 << k;
        if (n - k + 1 < m) return false;

        vector<bool> vis(m, false);
        int cnt = 0, curr = 0;

        for (int i = 0; i < n; i++) {
            curr = ((curr << 1) & (m - 1)) | (s[i] - '0');
            if (i >= k - 1 && !vis[curr]) {
                vis[curr] = true;
                cnt++;
            }
        }
        return cnt == m;
    }
};