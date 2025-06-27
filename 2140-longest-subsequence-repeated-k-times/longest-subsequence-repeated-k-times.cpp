class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        auto check = [&](const string& t, int k) {
            int i = 0;
            for (char c : s) {
                if (c == t[i]) {
                    i++;
                    if (i == t.size()) {
                        if (--k == 0) return true;
                        i = 0;
                    }
                }
            }
            return false;
        };
        int cnt[26] = {};
        for (char c : s) cnt[c - 'a']++;
        string cs;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] >= k) cs += char('a' + i);
        }
        queue<string> q;
        q.push("");
        string res;
        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            for (char c : cs) {
                string next = cur + c;
                if (check(next, k)) {
                    res = next;
                    q.push(next);
                }
            }
        }
        return res;
    }
};
