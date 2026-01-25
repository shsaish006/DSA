class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k == 1) return 0;
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        int i = 0, j = 0;
        while(j < nums.size()){
            if(j - i + 1 == k){
                ans = min(ans, nums[j] - nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};
