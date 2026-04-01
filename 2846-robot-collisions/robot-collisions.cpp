class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& a, vector<int>& b, string s) {
        int n = a.size();
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;

        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return a[i] < a[j];
        });

        vector<int> d;
        vector<int> on(n, 1);

        for (int i = 0; i < n; i++) {
            int curr = idx[i];

            if (s[curr] == 'R') {
                d.push_back(curr);
            } else {
                while (!d.empty() && b[curr] > 0) {
                    int val = d.back();

                    if (b[val] < b[curr]) {
                        d.pop_back();
                        b[curr]--;
                        on[val] = 0;
                    } else if (b[val] > b[curr]) {
                        b[val]--;
                        on[curr] = 0;
                        b[curr] = 0;
                    } else {
                        d.pop_back();
                        on[val] = 0;
                        on[curr] = 0;
                        b[val] = 0;
                        b[curr] = 0;
                    }
                }
            }
        }

        vector<int> vals;
        for (int i = 0; i < n; i++) {
            if (on[i] && b[i] > 0) vals.push_back(b[i]);
        }
        return vals;
    }};