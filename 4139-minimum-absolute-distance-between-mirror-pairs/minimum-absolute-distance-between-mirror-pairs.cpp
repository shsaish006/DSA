class Solution {
public:
    int f(int x) {
        int y = 0;
        while (x > 0) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        return y;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = n + 1;
        unordered_map<int, int> pos;

        for (int i = 0; i < n; i++) {
            auto it = pos.find(nums[i]);
            if (it != pos.end()) {
                ans = min(ans, i - it->second);
            }
            pos[f(nums[i])] = i;
        }

        return ans == n + 1 ? -1 : ans;
    }
};