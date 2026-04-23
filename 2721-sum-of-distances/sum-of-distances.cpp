class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int a = nums.size();
        vector<long long> ans(a);
        unordered_map<int, vector<int>> d;

        for (int i = 0; i < a; i++) d[nums[i]].push_back(i);

        for (auto &it : d) {
            vector<int> &vals = it.second;
            int b = vals.size();

            vector<long long> temp(b + 1);
            for (int i = 0; i < b; i++) temp[i + 1] = temp[i] + vals[i];

            for (int i = 0; i < b; i++) {
                long long left = 1LL * vals[i] * i - temp[i];
                long long right = (temp[b] - temp[i + 1]) - 1LL * vals[i] * (b - i - 1);
                ans[vals[i]] = left + right;
            }
        }
        return ans;
    }
};