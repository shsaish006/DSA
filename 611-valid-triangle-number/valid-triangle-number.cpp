class Solution {
public:
    int triangleNumber(vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size(), r = 0;
        for (int i = n - 1; i >= 2; --i) {
            int l = 0, m = i - 1;
            while (l < m) {
                if (a[l] + a[m] > a[i]) {
                    r += m - l;
                    --m;
                } else {
                    ++l;
                }
            }
        }
        return r;
    }};