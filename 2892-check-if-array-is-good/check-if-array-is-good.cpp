class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;
        vector<int> cnt(201);

        for (auto x : nums) cnt[x]++;

        if (cnt[n] != 2) return 0;

        for (int i = 1; i < n; i++)
            if (cnt[i] != 1)
                return 0;
        return 1;
    }
};