class Solution {
public:
    double angleClock(int h, int m) {
        double a = abs(30 * h + 0.5 * m - 6 * m);
        return min(a, 360 - a);
    }
};