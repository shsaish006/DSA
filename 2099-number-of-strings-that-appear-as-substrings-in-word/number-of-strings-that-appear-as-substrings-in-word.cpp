class Solution {
public:
    int numOfStrings(vector<string>& p, string w) {
        int c = 0;
        for (auto &s : p)
            c += search(w.begin(), w.end(), s.begin(), s.end()) != w.end();
        return c;
    }
};