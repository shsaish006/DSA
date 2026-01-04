class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int s = 0;
        for (int val : nums) s += calc(val);
        return s;
    }

    int calc(int val) {
        int cnt = 0;
        int s = 0;
        for (int i = 1; i * i <= val; i++) {
            if (val % i == 0) {
                int a = i;
                int b = val / i;
                if (a == b) {
                    cnt++;
                    s += a;
                } else {
                    cnt += 2;
                    s += a + b;
                }
                if (cnt > 4) return 0;
            }
        }
        return cnt == 4 ? s : 0;
    }
};
