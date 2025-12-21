class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<bool> st(n - 1, false);
        int ans = 0;
        for (int j = 0; j < m; ++j) {
            bool mustDel = false;
            for (int i = 0; i < n - 1; ++i) {
                if (!st[i] && strs[i][j] > strs[i + 1][j]) {
                    mustDel = true;
                    break;
                }
            }
            if (mustDel) {
                ++ans;
            } else {
                for (int i = 0; i < n - 1; ++i) {
                    if (!st[i] && strs[i][j] < strs[i + 1][j]) {
                        st[i] = true;
                    }
                }
            }
        }
        return ans;
    }
};