class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int a = nums.size();
        vector<int> vals(2 * limit + 2, 0);
        for (int idx = 0; idx < a / 2; idx++) {
            int b = nums[idx];
            int c = nums[a - idx - 1];
            int d = min(b, c);
            int s = max(b, c);
            vals[2] += 2;
            vals[d + 1] -= 1;
            vals[b + c] -= 1;
            vals[b + c + 1] += 1;
            vals[s + limit + 1] += 1;
        }

        int ans = a;
        int curr = 0;
        for (int idx = 2; idx <= 2 * limit; idx++) {
            curr += vals[idx];
            ans = min(ans, curr);
        }

        return ans;
    }
};