class Solution {
public:
    int minDeletionSize(vector<string>& s) {
        int n = s.size();
        int m = s[0].size();
        vector<int> a(n - 1, 0);
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            int val = 0;
            for (int i = 0; i < n - 1; i++) {
                if (!a[i] && s[i][j] > s[i + 1][j]) {
                    val = 1;
                    break;
                }
            }
            if (val) {
                cnt++;
            } else {
                for (int i = 0; i < n - 1; i++) {
                    if (!a[i] && s[i][j] < s[i + 1][j]) {
                        a[i] = 1;
                    }
                }
            }
        }
        return cnt;
    }
};
