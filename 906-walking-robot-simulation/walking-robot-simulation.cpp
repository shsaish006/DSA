class Solution {
public:
    struct H {
        size_t operator()(const pair<int,int>& a) const {
            return ((uint64_t)(uint32_t)a.first << 32) ^ (uint32_t)a.second;
        }
    };

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<pair<int,int>, H> s;
        for (auto &a : obstacles) s.insert({a[0], a[1]});

        vector<pair<int,int>> d = {{0,1},{1,0},{0,-1},{-1,0}};
        int x = 0, y = 0, idx = 0, ans = 0;

        for (int a : commands) {
            if (a == -1) {
                idx = (idx + 1) % 4;
            } else if (a == -2) {
                idx = (idx + 3) % 4;
            } else {
                for (int i = 0; i < a; i++) {
                    int nx = x + d[idx].first;
                    int ny = y + d[idx].second;
                    if (s.find({nx, ny}) != s.end()) break;
                    x = nx;
                    y = ny;
                    ans = max(ans, x * x + y * y);
                }
            }
        }

        return ans;
    }
};