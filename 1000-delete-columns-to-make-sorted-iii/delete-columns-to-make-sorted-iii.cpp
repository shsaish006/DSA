class Solution {
public:
    int minDeletionSize(vector<string>& s) {
        int n = s[0].size();
        int cnt = s.size();
        vector<vector<int>> b(n, vector<int>(n, 1));
        for (int j = 0; j < n; ++j) {
            for (int i = j + 1; i < n; ++i) {
                for (int k = 0; k < cnt; ++k) {
                    if (s[k][j] > s[k][i]) {
                        b[j][i] = 0;
                        break;
                    }
                }
            }
        }
        vector<int> a(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (b[j][i]) {
                    a[i] = max(a[i], a[j] + 1);
                }
            }
        }
        int val = 0;
        for (int i = 0; i < n; ++i) val = max(val, a[i]);
        return n - val;
    }
};
