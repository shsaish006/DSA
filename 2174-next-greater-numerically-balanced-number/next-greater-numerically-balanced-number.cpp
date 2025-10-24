class Solution {
public:
    int nextBeautifulNumber(int n) {
        for (int x = n + 1;; ++x) {
            int cnt[10] = {};
            int tmp = x;
            while (tmp) {
                ++cnt[tmp % 10];
                tmp /= 10;
            }
            tmp = x;
            bool valid = true;
            while (tmp) {
                if (cnt[tmp % 10] != tmp % 10) {
                    valid = false;
                    break;
                }
                tmp /= 10;
            }
            if (valid) return x;
        }


    }

    
};
