class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = 1e9;
        for (int x : nums) {
            int curr = 0;
            while (x) curr += x % 10, x /= 10;
            ans = min(ans, curr);
        }
        return ans;
    }
};