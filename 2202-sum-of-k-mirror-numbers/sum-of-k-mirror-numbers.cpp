class Solution {
public:
    long long kMirror(int k, int n) {
        long long ans = 0;
        int count = 0;

        for (int len = 1; count < n; ++len) {
            vector<long long> pals = generatePalindromes(len);
            for (long long num : pals) {
                if (isKPalindrome(num, k)) {
                    ans += num;
                    count++;
                    if (count == n)
                        return ans;
                }
            }
        }

        return ans;
    }

private:
    vector<long long> generatePalindromes(int len) {
        vector<long long> res;
        int half = (len + 1) / 2;
        int start = pow(10, half - 1);
        int end = pow(10, half);

        for (int i = start; i < end; ++i) {
            string first = to_string(i);
            string second = first;
            if (len % 2 == 1)
                second.pop_back();
            reverse(second.begin(), second.end());
            res.push_back(stoll(first + second));
        }
        return res;
    }

    bool isKPalindrome(long long x, int k) {
        vector<int> digits;
        while (x > 0) {
            digits.push_back(x % k);
            x /= k;
        }
        for (int i = 0, j = digits.size() - 1; i < j; ++i, --j)
            if (digits[i] != digits[j])
                return false;
        return true;
    }
};
