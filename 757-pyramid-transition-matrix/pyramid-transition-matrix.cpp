class Solution {
public:
    int d[7][7];
    unordered_map<string,int> o;

    bool build(string& curr, int idx, string& nxt) {
        if (idx + 1 == (int)curr.size()) {
            return dfs(nxt);
        }
        int a = curr[idx] - 'A';
        int b = curr[idx + 1] - 'A';
        int val = d[a][b];
        for (int i = 0; i < 7; i++) {
            if ((val >> i) & 1) {
                nxt.push_back(char('A' + i));
                if (build(curr, idx + 1, nxt)) return true;
                nxt.pop_back();
            }
        }
        return false;
    }

    bool dfs(string curr) {
        if (curr.size() == 1) return true;
        if (o.count(curr)) return o[curr];
        string nxt = "";
        bool val = build(curr, 0, nxt);
        o[curr] = val;
        return val;
    }

    bool pyramidTransition(string s, vector<string>& vals) {
        memset(d, 0, sizeof(d));
        for (auto& temp : vals) {
            int a = temp[0] - 'A';
            int b = temp[1] - 'A';
            int c = temp[2] - 'A';
            d[a][b] |= (1 << c);
        }
        return dfs(s);
    }
};