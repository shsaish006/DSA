class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> a;
        
        for (int i = 0; i < n; i++) {
            a[nums[i]].push_back(i);
        }

        vector<int> ans;
        for (int i : queries) {
            vector<int>& b = a[nums[i]];
            
            if (b.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            int c = lower_bound(b.begin(), b.end(), i) - b.begin();
            int d = b[(c - 1 + b.size()) % b.size()];
            int s = b[(c + 1) % b.size()];

            int o = abs(i - d);
            o = min(o, n - o);

            int on = abs(i - s);
            on = min(on, n - on);

            ans.push_back(min(o, on));
        }
        return ans;
    }};