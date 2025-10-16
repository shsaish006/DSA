class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> cnt(value);
        for (int x : nums) cnt[(x % value + value) % value]++;
        for (int i = 0;; i++) if (cnt[i % value]-- == 0) return i;
    }
};