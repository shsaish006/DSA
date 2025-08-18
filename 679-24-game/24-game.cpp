#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& a) {
        vector<double> b;
        for (int c : a) b.push_back((double)c);
        return f(b);
    }

private:
    bool f(vector<double>& a) {
        int b = a.size();
        if (b == 1) return fabs(a[0] - 24) < 1e-6;
        for (int c = 0; c < b; c++) {
            for (int d = 0; d < b; d++) {
                if (c == d) continue;
                vector<double> e;
                for (int g = 0; g < b; g++) 
                    if (g != c && g != d) e.push_back(a[g]);
                for (int h = 0; h < 4; h++) {
                    if (h == 0) e.push_back(a[c] + a[d]);
                    else if (h == 1) e.push_back(a[c] - a[d]);
                    else if (h == 2) e.push_back(a[c] * a[d]);
                    else if (h == 3 && a[d] != 0) e.push_back(a[c] / a[d]);
                    else continue;
                    if (f(e)) return true;
                    e.pop_back();
                }
            }
        }
        return false;
    }
};
