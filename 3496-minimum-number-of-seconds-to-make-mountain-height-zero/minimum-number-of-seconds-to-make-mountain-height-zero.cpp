class Solution {
public:
    long long minNumberOfSeconds(int a, vector<int>& nums) {
        long long b = 1, c = 1e16;
        while (b < c) {
            long long d = (b + c) / 2;
            long long cnt = 0;
            for (int i = 0; i < nums.size(); i++)
                cnt += (long long)(sqrt(d * 2.0 / nums[i] + 0.25) - 0.5);
            if (cnt >= a) c = d;
            else b = d + 1;
        }
        return b;
    }
};