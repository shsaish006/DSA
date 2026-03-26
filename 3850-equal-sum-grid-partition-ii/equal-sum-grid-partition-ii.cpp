class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int a = grid.size(), b = grid[0].size();

        for (int on = 0; on < 2; on++) {
            int c = on ? b : a;
            int d = on ? a : b;

            long long s = 0;
            unordered_map<long long, int> cnt, nxt;

            for (int i = 0; i < c; i++) {
                for (int j = 0; j < d; j++) {
                    int val = on ? grid[j][i] : grid[i][j];
                    s += val;
                    nxt[val]++;
                }
            }

            long long curr = 0;

            for (int i = 0; i < c - 1; i++) {
                for (int j = 0; j < d; j++) {
                    int val = on ? grid[j][i] : grid[i][j];
                    curr += val;
                    s -= val;
                    cnt[val]++;
                    nxt[val]--;
                }

                if (curr == s) return true;

                if (curr < s) {
                    long long diff = s - curr;
                    if (nxt[diff] > 0) {
                        if ((c - i - 1 > 1 && d > 1) ||
                            (i == c - 2 && (((on ? grid[0][i + 1] : grid[i + 1][0]) == diff) || ((on ? grid[d - 1][i + 1] : grid[i + 1][d - 1]) == diff))) ||
                            (d == 1 && (((on ? grid[0][i + 1] : grid[i + 1][0]) == diff) || ((on ? grid[0][c - 1] : grid[c - 1][0]) == diff)))) {
                            return true;
                        }
                    }
                } else {
                    long long diff = curr - s;
                    if (cnt[diff] > 0) {
                        if ((i + 1 > 1 && d > 1) ||
                            (i == 0 && (((on ? grid[0][0] : grid[0][0]) == diff) || ((on ? grid[d - 1][0] : grid[0][d - 1]) == diff))) ||
                            (d == 1 && (((on ? grid[0][0] : grid[0][0]) == diff) || ((on ? grid[0][i] : grid[i][0]) == diff)))) {
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }};