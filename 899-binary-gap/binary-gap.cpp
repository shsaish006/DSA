class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        int prev = -1;
        int idx = 0;

        while (n > 0) {
            if (n & 1) {
                if (prev != -1) {
                    ans = max(ans, idx - prev);
                }
                prev = idx;
            }
            idx++;
            n >>= 1;
        }

        return ans;
    }
};