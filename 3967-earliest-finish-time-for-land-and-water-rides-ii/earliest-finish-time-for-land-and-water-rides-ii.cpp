// class Solution {
// public:
//     int earliestFinishTime(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
//         int n = a.size(), m = c.size(), ans = INT_MAX;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 ans = min(ans, max(a[i], 0) + b[i] + max(c[j], a[i] + b[i]) + d[j] - (a[i] + b[i]));
//                 ans = min(ans, max(c[j], 0) + d[j] + max(a[i], c[j] + d[j]) + b[i] - (c[j] + d[j]));
//             }
//         }
//     return ans;
//     }
// };
// class Solution {
// public:
//     int earliestFinishTime(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
//         int n = a.size(), m = c.size();
//         int ans = INT_MAX;

//         int lm = INT_MAX, wm = INT_MAX;

//         for (int i = 0; i < n; i++) lm = min(lm, a[i] + b[i]);
//         for (int i = 0; i < m; i++) wm = min(wm, c[i] + d[i]);

//         for (int i = 0; i < n; i++) {
//             int e1 = a[i] + b[i];
//             for (int j = 0; j < m; j++) {
//                 int e2 = c[j] + d[j];

//                 ans = min(ans, max(e1, c[j]) + d[j]);
//                 ans = min(ans, max(e2, a[i]) + b[i]);
//             }
//         }

//         return ans;
//     }
// };
class Solution {
public:
    int earliestFinishTime(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        int x = calc(a, b, c, d);
        int y = calc(c, d, a, b);
        return min(x, y);
    }

    int calc(vector<int>& a1, vector<int>& t1, vector<int>& a2, vector<int>& t2) {
        int m = INT_MAX;

        for (int i = 0; i < a1.size(); i++)
            m = min(m, a1[i] + t1[i]);

        int ans = INT_MAX;

        for (int i = 0; i < a2.size(); i++)
            ans = min(ans, max(m, a2[i]) + t2[i]);

        return ans;
    }
};