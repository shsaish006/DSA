class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> a;
        for (int i = 0; i < nums.size(); i++) {
            a[nums[i]].push_back(i);
        }

        int o = 1e9;

        for (auto &p : a) {
            vector<int> &b = p.second;
            for (int i = 0; i + 2 < b.size(); i++) {
                o = min(o, (b[i + 2] - b[i]) * 2);
            }
        }

        return o == 1e9 ? -1 : o;
    }};