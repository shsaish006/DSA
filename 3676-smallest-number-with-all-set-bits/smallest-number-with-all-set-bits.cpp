class Solution {
public:
    int smallestNumber(int n) {
        int a = 1;
        while (a <= n) a *= 2;
        return a - 1;
    }
};