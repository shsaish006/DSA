class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        auto noZero = [&](int x) {
            while (x > 0) {
                if (x % 10 == 0) return false;
                x /= 10;
            }
            return true;
        };
        
        for (int a = 1; a < n; ++a) {
            int b = n - a;
            if (noZero(a) && noZero(b)) return {a, b};
        }
        return {};
    }
};