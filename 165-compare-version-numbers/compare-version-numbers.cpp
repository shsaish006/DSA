class Solution {
public:
    int compareVersion(string v1, string v2) {
        vector<int> a, b;
        split(v1, a);
        split(v2, b);
        int n = max(a.size(), b.size());
        for (int i = 0; i < n; i++) {
            int x = i < a.size() ? a[i] : 0;
            int y = i < b.size() ? b[i] : 0;
            if (x != y) return x < y ? -1 : 1;
        }
        return 0;
    }
private:
    void split(const string& s, vector<int>& out) {
        int num = 0;
        for (char c : s) {
            if (c == '.') {
                out.push_back(num);
                num = 0;
            } else {
                num = num * 10 + (c - '0');
            }
        }
        out.push_back(num);
    }
};
