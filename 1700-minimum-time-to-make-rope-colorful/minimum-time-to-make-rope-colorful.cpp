class Solution {
public:
    int minCost(string a, vector<int>& b) {
        int s = 0;
        for (int i = 1; i < a.size(); i++) {
            if (a[i] == a[i - 1]) {
                s += min(b[i], b[i - 1]);
                b[i] = max(b[i], b[i - 1]);
            }
        }
        return s;
    }
};