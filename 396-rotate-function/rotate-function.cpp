class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int a = nums.size();
        long long s = 0, curr = 0;

        for (int i = 0; i < a; i++) {
            s += nums[i];
            curr += 1LL * i * nums[i];
        }

        long long val = curr;

        for (int i = a - 1; i > 0; i--) {
            curr += s - 1LL * a * nums[i];
            if (curr > val) val = curr;
        }

        return val;
    }};