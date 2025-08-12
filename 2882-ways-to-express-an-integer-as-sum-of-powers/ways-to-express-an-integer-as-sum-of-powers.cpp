class Solution {
public:
    int numberOfWays(int a, int b) {
        const int c = 1e9 + 7;
        int d[a + 1][a + 1];
        memset(d, 0, sizeof(d));
        d[0][0] = 1;
        for (int i = 1; i <= a; ++i) {
            long long k = (long long)pow(i, b);
            for (int j = 0; j <= a; ++j) {
                d[i][j] = d[i - 1][j];
                if (k <= j) {
                    d[i][j] = (d[i][j] + d[i - 1][j - k]) % c;
                }
            }
        }
        return d[a][a];
    }

    
};
