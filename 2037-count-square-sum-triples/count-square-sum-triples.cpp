class Solution {
public:
    int countTriples(int n) {
        vector<int> sq(n + 1);
        for (int i = 1; i <= n; i++) sq[i] = i * i;
        int ans = 0;
        for (int a = 1; a < n; a++) {
            for (int b = 1; b < n; b++) {
                int s = sq[a] + sq[b];
                int c = sqrt(s);
                if (c <= n && c * c == s) ans++;
            }
        }

        return ans;
    }

};