class Solution {
public:
    int maxFrequency(vector<int>& a, int k, int o) {
        unordered_map<int, int> cnt;
        map<int, int> d;
        for (int val : a) {
            cnt[val]++;
            d[val];
            d[val - k]++;
            d[val + k + 1]--;
        }
        int ans = 0, s = 0;
        for (auto &p : d) {
            s += p.second;
            ans = max(ans, min(s, cnt[p.first] + o));
        }
        return ans;
    }};