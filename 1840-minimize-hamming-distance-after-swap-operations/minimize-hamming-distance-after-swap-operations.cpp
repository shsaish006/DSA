class Solution {
public:
    vector<int> a;

    int f(int b) {
        if (a[b] == b) return b;
        return a[b] = f(a[b]);
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        a.resize(n);
        iota(a.begin(), a.end(), 0);

        for (auto &b : allowedSwaps) {
            int c = f(b[0]), d = f(b[1]);
            if (c != d) a[c] = d;
        }

        unordered_map<int, vector<int>> b, c;
        for (int i = 0; i < n; i++) {
            int d = f(i);
            b[d].push_back(source[i]);
            c[d].push_back(target[i]);
        }

        int ans = 0;
        for (auto &d : b) {
            auto &s = d.second;
            auto &o = c[d.first];
            sort(s.begin(), s.end());
            sort(o.begin(), o.end());

            int i = 0, j = 0, cnt = 0;
            while (i < s.size() && j < o.size()) {
                if (s[i] == o[j]) {
                    cnt++;
                    i++;
                    j++;
                } else if (s[i] < o[j]) {
                    i++;
                } else {
                    j++;
                }
            }
            ans += (int)s.size() - cnt;
        }

        return ans;
    }
};