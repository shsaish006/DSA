class Solution {
public:
    vector<string> removeAnagrams(vector<string>& a) {
        auto f = [](string& s, string& t) {
            if (s.size() != t.size()) return 1;
            int c[26]{};
            for (auto& x : s) c[x - 'a']++;
            for (auto& x : t) if (--c[x - 'a'] < 0) return 1;
            return 0;
        };
        vector<string> o = {a[0]};
        for (int i = 1; i < a.size(); i++) if (f(a[i - 1], a[i])) o.push_back(a[i]);
        return o;
    }
};