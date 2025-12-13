class Solution {
public:
    vector<string> validateCoupons(vector<string>& a,
                                   vector<string>& b,
                                   vector<bool>& c) {
        unordered_set<string> d = {
            "electronics",
            "grocery",
            "pharmacy",
            "restaurant"
        };

        vector<int> idx;
        int n = a.size();

        for (int i = 0; i < n; i++) {
            if (c[i] && d.count(b[i]) && ok(a[i])) {
                idx.push_back(i);
            }
        }

        sort(idx.begin(), idx.end(), [&](int i, int j) {
            if (b[i] != b[j]) return b[i] < b[j];
            return a[i] < a[j];
        });

        vector<string> vals;
        for (int i : idx) {
            vals.push_back(a[i]);
        }
        return vals;
    }

private:
    bool ok(string s) {
        if (s.size() == 0) return false;
        for (char c : s) {
            if (!isalnum(c) && c != '_') return false;
        }
        return true;
    }
};