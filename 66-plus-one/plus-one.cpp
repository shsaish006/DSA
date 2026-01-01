class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int curr = 1;
        for (int i = n - 1; i >= 0; --i) {
            curr += digits[i];
            digits[i] = curr % 10;
            curr /= 10;
        }
        if (curr) digits.insert(digits.begin(), curr);
        return digits;
    }
};