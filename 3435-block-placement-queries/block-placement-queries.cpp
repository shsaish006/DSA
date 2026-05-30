// class Solution {
// public:
//     vector<bool> getResults(vector<vector<int>>& q) {
//         set<int> s = {0, 50000};
//         vector<bool> ans;

//         for (auto &v : q) {
//             if (v[0] == 1) {
//                 s.insert(v[1]);
//             } else {
//                 int x = v[1], sz = v[2];

//                 vector<int> a;
//                 for (auto it = s.begin(); it != s.end() && *it <= x; it++) {
//                     a.push_back(*it);
//                 }

//                 int mx = 0;

//                 for (int i = 1; i < (int)a.size(); i++) {
//                     mx = max(mx, a[i] - a[i - 1]);
//                 }

//                 if (!a.empty()) {
//                     mx = max(mx, x - a.back());
//                 }

//                 ans.push_back(mx >= sz);
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& q) {
        int n = 50001;
        int b = 225;

        vector<int> nums(n, 0), mx((n + b - 1) / b, 0);

        auto upd = [&](int idx, int val) {
            nums[idx] = val;
            int id = idx / b;
            mx[id] = 0;

            int l = id * b;
            int r = min(n - 1, l + b - 1);

            for (int i = l; i <= r; i++) {
                mx[id] = max(mx[id], nums[i]);
            }
        };

        set<int> s = {0, 50000};

        upd(50000, 50000);

        vector<bool> ans;

        for (auto &v : q) {
            if (v[0] == 1) {
                int x = v[1];

                auto it = s.upper_bound(x);

                int r = *it;
                int l = *prev(it);

                upd(x, x - l);
                upd(r, r - x);

                s.insert(x);
            } else {
                int x = v[1];
                int sz = v[2];

                auto it = prev(s.upper_bound(x));
                int p = *it;

                int res = 0;

                int L = 0, R = p;

                while (L <= R) {
                    if (L % b == 0 && L + b - 1 <= R) {
                        res = max(res, mx[L / b]);
                        L += b;
                    } else {
                        res = max(res, nums[L]);
                        L++;
                    }
                }

                res = max(res, x - p);

                ans.push_back(res >= sz);
            }
        }

        return ans;
    }
};