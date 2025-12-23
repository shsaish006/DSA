class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int a = n / 2;
        int b = n - a;
        vector<int> l, r;

        for (int i = 0; i < (1 << a); i++) {
            int s = 0;
            for (int j = 0; j < a; j++) {
                if (i & (1 << j)) s += nums[j];
            }
            l.push_back(s);
        }

        for (int i = 0; i < (1 << b); i++) {
            int s = 0;
            for (int j = 0; j < b; j++) {
                if (i & (1 << j)) s += nums[a + j];
            }
            r.push_back(s);
        }

        sort(r.begin(), r.end());
        int val = INT_MAX;

        for (int x : l) {
            int target = goal - x;
            int idx = lower_bound(r.begin(), r.end(), target) - r.begin();
            if (idx < r.size()) val = min(val, abs(target - r[idx]));
            if (idx > 0) val = min(val, abs(target - r[idx - 1]));
        }

        return val;
    }
};
