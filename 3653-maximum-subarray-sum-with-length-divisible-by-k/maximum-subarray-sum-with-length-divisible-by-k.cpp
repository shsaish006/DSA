class Solution {
public:
    long long maxSubarraySum(vector<int>& vals, int k) {
        long long inf = 4e18;
        vector<long long> mp(k, inf);
        
        long long s = 0, ans = -inf;
        mp[0] = 0;
        
        for(int idx = 0; idx < vals.size(); idx++) {
            s += vals[idx];
            int curr = (idx + 1) % k;
            ans = max(ans, s - mp[curr]);
            mp[curr] = min(mp[curr], s);
        }
        return ans;
    }
};