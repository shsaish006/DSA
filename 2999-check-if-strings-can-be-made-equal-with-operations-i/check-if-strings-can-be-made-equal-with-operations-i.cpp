class Solution {
public:
    bool canBeEqual(string a, string b) {
        vector<vector<int>> c(2, vector<int>(26));
        for (int i = 0; i < a.size(); i++)
            c[i&1][a[i]-'a']++, c[i&1][b[i]-'a']--;
        for (auto &d : c)
            for (int v : d)
                if (v) return 0;
        return 1;
    }
};