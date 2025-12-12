uint32_t offline[100] = {0};

class Solution {
public:
    static vector<int> countMentions(const int n, vector<vector<string>>& a) noexcept {
        vector<int> users(n, 0);
        int all = 0;

        sort(a.begin(), a.end(), [](const vector<string>& x, const vector<string>& y) {
            int tx = stoi(x[1]), ty = stoi(y[1]);
            if (tx != ty) return tx < ty;
            return x[0][0] == 'O';
        });

        for (int i = 0; i < (int)a.size(); ++i) {
            const auto& e = a[i];
            if (e[0][0] == 'O') {
                offline[stoi(e[2])] = stoi(e[1]) + 60;
            } else {
                const string& s = e[2];
                if (s[0] == 'A') { ++all; continue; }
                if (s[0] == 'H') {
                    int t = stoi(e[1]);
                    for (int id = 0; id < n; ++id) if (t >= (int)offline[id]) ++users[id];
                    continue;
                }
                int L = s.size();
                for (int j = 2; j < L - 1; j += 4) {
                    int id = s[j] - '0';
                    if (s[j + 1] != ' ') id = id * 10 + (s[++j] - '0');
                    ++users[id];
                }
                if (s[L - 2] == 'd') ++users[s[L - 1] - '0'];
            }
        }

        for (int i = 0; i < n; ++i) users[i] += all;
        memset(offline, 0, sizeof(offline));
        return users;
    }
};
