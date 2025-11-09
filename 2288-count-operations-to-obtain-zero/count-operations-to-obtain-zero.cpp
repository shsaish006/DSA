class Solution {
public:
    int countOperations(int a, int b) {
        int ans = 0;
        while (a && b) {
            if (a >= b) ans += a / b, a %= b;
            else ans += b / a, b %= a;
        }
        return ans;
    }
};