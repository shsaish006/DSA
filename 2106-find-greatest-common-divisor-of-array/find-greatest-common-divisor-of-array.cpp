class Solution {
public:
    int findGCD(vector<int>& nums) {
        int a = nums[0], b = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            a = min(a, nums[i]);
            b = max(b, nums[i]);
        }
        while (b % a) {
            int c = b % a;
            b = a;
            a = c;
        }

        return a;
    }
};