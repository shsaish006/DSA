// class Solution {
// public:
//     int minDeletionSize(vector<string>& strs) {
//         int n = strs[0].size();
//         vector<int> f(n, 1);
//         for (int i = 1; i < n; ++i) {
//             for (int j = 0; j < i; ++j) {
//                 if (ranges::all_of(strs, [&](const string& s) { return s[j] <= s[i]; })) {
//                     f[i] = max(f[i], f[j] + 1);
//                 }
//             }
//         }
//         return n - ranges::max(f);
//     }
// };

class Solution {
public:
    int minDeletionSize(vector<string>& s) {
        int n = s[0].size();
        int cnt = s.size();
        vector<int> a(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int ok = 1;
                for (int k = 0; k < cnt; ++k) {
                    if (s[k][j] > s[k][i]) {
                        ok = 0;
                        break;
                    }
                }
                if (ok) a[i] = max(a[i], a[j] + 1);
            }
        }
        int val = 0;
        for (int i = 0; i < n; ++i) val = max(val, a[i]);
        return n - val;
    }
};
