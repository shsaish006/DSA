class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n == 0) return 0;
        int b = 0;
        while ((1 << (b + 1)) <= n) b++;
        return (1 << (b + 1)) - 1 - minimumOneBitOperations(n ^ (1 << b));
    }
};
