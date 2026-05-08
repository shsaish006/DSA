class Solution {
public:
    int minJumps(vector<int>& nums) {
        int a = nums.size();
        int b = *max_element(nums.begin(), nums.end());

        vector<int> vals(b + 1);
        for (int i = 2; i <= b; i++) {
            if (!vals[i]) {
                vals[i] = i;
                if ((long long)i * i <= b) {
                    for (long long j = 1LL * i * i; j <= b; j += i) {
                        if (!vals[j]) vals[j] = i;
                    }
                }
            }
        }

        unordered_map<int, vector<int>> idx;
        for (int i = 0; i < a; i++) {
            int c = nums[i];
            while (c > 1) {
                int d = vals[c];
                idx[d].push_back(i);
                while (c % d == 0) c /= d;
            }
        }

        queue<int> q;
        vector<int> vis(a);
        q.push(0);
        vis[0] = 1;

        int cnt = 0;

        while (!q.empty()) {
            int s = q.size();

            while (s--) {
                int i = q.front();
                q.pop();

                if (i == a - 1) return cnt;

                if (i + 1 < a && !vis[i + 1]) {
                    vis[i + 1] = 1;
                    q.push(i + 1);
                }

                if (i - 1 >= 0 && !vis[i - 1]) {
                    vis[i - 1] = 1;
                    q.push(i - 1);
                }

                int c = nums[i];
                if (c > 1 && vals[c] == c) {
                    for (int j : idx[c]) {
                        if (!vis[j]) {
                            vis[j] = 1;
                            q.push(j);
                        }
                    }
                    idx[c].clear();
                }
            }

            cnt++;
        }

        return -1;
    }
};