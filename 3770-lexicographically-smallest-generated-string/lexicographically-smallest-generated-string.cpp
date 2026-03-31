class Solution {
public:
    string generateString(string s, string t) {
        int a = s.size(), b = t.size(), c = a + b - 1;
        string d(c, 'a');
        vector<int> on(c);

        for (int i = 0; i < a; i++) {
            if (s[i] == 'F') continue;
            for (int j = 0; j < b; j++) {
                int idx = i + j;
                if (on[idx] && d[idx] != t[j]) return "";
                d[idx] = t[j];
                on[idx] = 1;
            }
        }

        for (int i = 0; i < a; i++) {
            if (s[i] == 'T') continue;
            int cnt = 1, idx = -1;
            for (int j = 0; j < b; j++) {
                if (d[i + j] != t[j]) {
                    cnt = 0;
                    break;
                }
                if (!on[i + j]) idx = i + j;
            }
            if (!cnt) continue;
            if (idx == -1) return "";
            d[idx] = d[idx] == 'a' ? 'b' : 'a';
            on[idx] = 1;
        }

        return d;
    }};