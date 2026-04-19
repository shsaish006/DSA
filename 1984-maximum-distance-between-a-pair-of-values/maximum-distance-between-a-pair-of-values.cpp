class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int a = nums1.size(), b = nums2.size();
        int i = 0, j = 0, ans = 0;
        
        while (i < a && j < b) {
            if (i > j) {
                j = i;
            }
            if (j < b && nums1[i] <= nums2[j]) {
                ans = max(ans, j - i);
                j++;
            } else {
                i++;
            }
        }
        
        return ans;
    }
};