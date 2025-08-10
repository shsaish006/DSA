class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = countDigits(n);
        for (int p = 1; p <= 1e9; p <<= 1)
            if (s == countDigits(p)) return true;
        return false;
    }

private:
    string countDigits(int x) {
        string res(10, 0);
        while (x) {
            res[x % 10]++;
            x /= 10;
        }
        return res;
    }
};
