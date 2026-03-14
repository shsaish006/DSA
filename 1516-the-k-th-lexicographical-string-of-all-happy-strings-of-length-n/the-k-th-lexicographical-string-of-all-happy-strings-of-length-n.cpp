class Solution {
public:
    string getHappyString(int n, int k) {
        string s = "";
        int a = 1;
        for (int i = 1; i < n; i++) a *= 2;

        if (k > 3 * a) return "";

        char nums[3] = {'a','b','c'};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                if (i && s.back() == nums[j]) continue;

                if (k > a) {
                    k -= a;
                } else {
                    s.push_back(nums[j]);
                    break;
                }
            }
            if (i < n - 1) a /= 2;
        }

        return s;
    }
};