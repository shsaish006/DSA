class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int mx = 0;
        for (int x : nums) {
            mx = max(mx, ++freq[x]);
        }

        int ans = 0;
        
        for (auto &p : freq) {
            if (p.second == mx) ans += p.second;
        }
        return ans;
    }
};
