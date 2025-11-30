class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long total = 0;
        for (int x : nums) total = (total + x) % p;

        if (total == 0) return 0;   // already divisible

        unordered_map<int,int> pos;
        pos[0] = -1;

        long pref = 0;
        int n = nums.size();
        int best = n;

        for (int i = 0; i < n; i++) {
            pref = (pref + nums[i]) % p;

            long need = (pref - total + p) % p;

            auto it = pos.find(need);
            if (it != pos.end()) {
                best = min(best, i - it->second);
            }

            pos[pref] = i;
        }

        return best == n ? -1 : best;
    }
};