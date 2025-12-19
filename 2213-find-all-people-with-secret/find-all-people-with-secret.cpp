class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) a[i] = i;

        function<int(int)> f = [&](int x) {
            if (a[x] == x) return x;
            return a[x] = f(a[x]);
        };

        auto u = [&](int x, int y) {
            x = f(x);
            y = f(y);
            if (x != y) a[y] = x;
        };

        vector<int> s(n);
        s[0] = 1;
        s[firstPerson] = 1;

        sort(meetings.begin(), meetings.end(), [&](auto& x, auto& y) {
            return x[2] < y[2];
        });

        int m = meetings.size();

        for (int i = 0; i < m; ) {
            int j = i;
            while (j + 1 < m && meetings[j + 1][2] == meetings[i][2]) j++;

            vector<int> vals;
            for (int k = i; k <= j; k++) {
                u(meetings[k][0], meetings[k][1]);
                vals.push_back(meetings[k][0]);
                vals.push_back(meetings[k][1]);
            }

            unordered_set<int> o;
            for (int x : vals) {
                if (s[x]) o.insert(f(x));
            }

            for (int x : vals) {
                if (o.count(f(x))) s[x] = 1;
                else a[x] = x;
            }

            i = j + 1;
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (s[i]) ans.push_back(i);
        }
        return ans;}};