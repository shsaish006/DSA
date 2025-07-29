class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& a) {
        int b = a.size();
        vector<int> c(32, -1);  // Last seen positions of each bit
        vector<int> d(b);       // Result array

        for (int e = b - 1; ~e; --e) {
            for (int f = 0; f < 32; ++f) {
                if ((a[e] >> f) & 1) {
                    c[f] = e;
                }
            }

            int g = e;
            for (int f = 0; f < 32; ++f) {
                if (c[f] != -1) {
                    g = max(g, c[f]);
                }
            }

            d[e] = g - e + 1;
        }

        return d;
    }
};
