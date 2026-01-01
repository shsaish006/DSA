// class Solution {
// public:
//     vector<int> plusOne(vector<int>& digits) {
//         int n = digits.size();
//         int curr = 1;
//         for (int i = n - 1; i >= 0; --i) {
//             curr += digits[i];
//             digits[i] = curr % 10;
//             curr /= 10;
//         }
//         if (curr) digits.insert(digits.begin(), curr);
//         return digits;
//     }
// };
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int idx = n - 1;
        while (idx >= 0 && digits[idx] == 9) {
            digits[idx] = 0;
            idx--;
        }
        if (idx < 0) {
            digits.insert(digits.begin(), 1);
        } else {
            digits[idx]++;
        }
        return digits;
    }
};
