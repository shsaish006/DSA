class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int a = nums.size();
        vector<int> vals(a), nums2(a);
        nums2[0] = nums[0];
        for (int i = 1; i < a; i++) {
            nums2[i] = max(nums2[i - 1], nums[i]);
        }
        int b = nums[a - 1];
        vals[a - 1] = nums2[a - 1];
        for (int i = a - 2; i >= 0; i--) {
            if (nums2[i] > b) vals[i] = vals[i + 1];
            else vals[i] = nums2[i];

            b = min(b, nums[i]);
        }
        return vals;
    }
};