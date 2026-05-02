class Solution {
public:
    int rotatedDigits(int n) {
        int a = 0;
        for (int i = 1; i <= n; i++) {
            int b = i, c = 0, d = 0;
            while (b) {
                int s = b % 10;
                if (s == 3 || s == 4 || s == 7) {
                    c = 0;
                    break;
                }
                if (s == 2 || s == 5 || s == 6 || s == 9) c = 1;
                b /= 10;
            }
            a += c;
        }
        return a;
    }
};