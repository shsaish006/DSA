// class Solution {
// public:
//     char kthCharacter(long long k, vector<int>& operations) {
//         return helper(k, operations, operations.size(), 0);
//     }

// private:
//     char helper(long long k, const vector<int>& ops, int level, int accShift) {
//         if (level == 0) {
//             return 'a' + (accShift % 26);
//         }

//         long long half = 1LL << (level - 1);
//         if (k <= half) {
//             return helper(k, ops, level - 1, accShift);
//         } else {
//             return helper(k - half, ops, level - 1, accShift + ops[level - 1]);
//         }
//     }
// };
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long n = 1;
        int i = 0;
        while (n < k) {
            n *= 2;
            ++i;
        }
        int d = 0;
        while (n > 1) {
            if (k > n / 2) {
                k -= n / 2;
                d += operations[i - 1];
            }
            n /= 2;
            --i;
        }
        return 'a' + (d % 26);
    }
};