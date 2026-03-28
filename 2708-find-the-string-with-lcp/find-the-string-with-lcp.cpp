class Solution {
public:
    string findTheString(vector<vector<int>>& a) {
        int n = a.size();
        string s(n, ' ');
        
        for (int i = 0, c = 0; i < n; i++) {
            if (s[i] != ' ') {
                continue;
            }
            if (c == 26) {
                return "";
            }
            for (int j = i; j < n; j++) {
                if (a[i][j] > 0) {
                    s[j] = char('a' + c);
                }
            }
            c++;
        }
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s[i] == s[j]) {
                    int v = 1;
                    if (i + 1 < n && j + 1 < n) {
                        v += a[i + 1][j + 1];
                    }
                    if (a[i][j] != v) {
                        return "";
                    }
                } else {
                    if (a[i][j] != 0) {
                        return "";
                    }
                }
            }
        }
        
        return s;
    }
};