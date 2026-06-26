class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size(), s = n + 1;
        vector<int> bit(2 * n + 2);
        auto add = [&](int i) {
            while (i <= 2 * n + 1) {
                bit[i]++;
                i += i & -i;
            }
        };
auto sum = [&](int i) {
            int r = 0;
            while (i) {
                r += bit[i];
                i -= i & -i;
            }
            return r;
        };
        add(s);
        long long ans = 0;

        for (int x : nums) {
            s += (x == target ? 1 : -1);
            ans += sum(s - 1);
            add(s);
        }

        return ans;
    }
};