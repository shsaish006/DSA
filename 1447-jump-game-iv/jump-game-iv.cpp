// class Solution {
// public:
//     int minJumps(vector<int>& arr) {
//         unordered_map<int, vector<int>> g;
//         int n = arr.size();
//         for (int i = 0; i < n; ++i) {
//             g[arr[i]].push_back(i);
//         }
//         vector<bool> vis(n);
//         queue<int> q{{0}};
//         vis[0] = true;
//         for (int ans = 0;; ++ans) {
//             for (int k = q.size(); k; --k) {
//                 int i = q.front();
//                 q.pop();
//                 if (i == n - 1) {
//                     return ans;
//                 }
//                 for (int j : g[arr[i]]) {
//                     if (!vis[j]) {
//                         vis[j] = true;
//                         q.push(j);
//                     }
//                 }
//                 g[arr[i]].clear();
//                 for (int j : {i - 1, i + 1}) {
//                     if (0 <= j && j < n && !vis[j]) {
//                         vis[j] = true;
//                         q.push(j);
//                     }
//                 }
//             }
//         }
//     }
// };
class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> vals;
        for (int i = 0; i < n; i++) {
            vals[nums[i]].push_back(i);
        }

        vector<int> dp(n, 1e9);
        dp[0] = 0;

        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int idx = q.front();
            q.pop();

            int curr = dp[idx];

            vector<int> nxt;

            if (idx - 1 >= 0)
                nxt.push_back(idx - 1);

            if (idx + 1 < n)
                nxt.push_back(idx + 1);

            for (auto &x : vals[nums[idx]])
                nxt.push_back(x);

            vals[nums[idx]].clear();

            for (auto &x : nxt) {
                if (dp[x] > curr + 1) {
                    dp[x] = curr + 1;
                    q.push(x);
                }
            }
        }

        return dp[n - 1];
    }
};