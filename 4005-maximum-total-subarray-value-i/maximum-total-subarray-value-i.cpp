class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        auto a = min_element(nums.begin(), nums.end());
        auto b = max_element(nums.begin(), nums.end());
        return 1LL * (*b - *a) * k;
    }
};