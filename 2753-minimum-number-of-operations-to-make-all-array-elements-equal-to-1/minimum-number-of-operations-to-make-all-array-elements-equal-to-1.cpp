class Solution {
public:
    int minOperations(vector<int>& a) {
        int n = a.size(), cnt = count(a.begin(), a.end(), 1);
        if (cnt) return n - cnt;
        int mi = n + 1;
        for (int i = 0; i < n; i++) {
            int g = 0;
            for (int j = i; j < n; j++) {
                g = gcd(g, a[j]);
                if (g == 1) {
                    mi = min(mi, j - i + 1);
                    break;
                }
            }
        }
        return mi > n ? -1 : (n + mi - 2);
    }

};






