class Solution {
public:
    int a, b;
    vector<vector<int>> nums;
    vector<int> vals = {-1, 0, 1, 0, -1};

    bool containsCycle(vector<vector<char>>& s) {
        a = s.size();
        b = s[0].size();
        nums.assign(a, vector<int>(b, 0));

        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (!nums[i][j]) {
                    queue<pair<int, int>> o;
                    queue<pair<int, int>> on;

                    o.push({i, j});
                    on.push({-1, -1});
                    nums[i][j] = 1;

                    while (!o.empty()) {
                        auto curr = o.front();
                        auto temp = on.front();
                        o.pop();
                        on.pop();

                        for (int k = 0; k < 4; k++) {
                            int c = curr.first + vals[k];
                            int d = curr.second + vals[k + 1];

                            if (c < 0 || d < 0 || c >= a || d >= b) continue;
                            if (s[c][d] != s[curr.first][curr.second]) continue;
                            if (c == temp.first && d == temp.second) continue;

                            if (nums[c][d]) return true;

                            nums[c][d] = 1;
                            o.push({c, d});
                            on.push(curr);
                        }
                    }
                }
            }
        }
        return false;
    }
};