class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 1; i + 1 < m; i++) {
            for (int j = 1; j + 1 < n; j++) {
                if (grid[i][j] != 5) continue;
                int a = grid[i-1][j-1], b = grid[i-1][j], c = grid[i-1][j+1];
                int d = grid[i][j-1],     e = grid[i][j],     f = grid[i][j+1];
                int g = grid[i+1][j-1], h = grid[i+1][j], k = grid[i+1][j+1];
                vector<int> vals = {a,b,c,d,e,f,g,h,k};
                vector<int> seen(10);
                bool ok = true;
                for (int v : vals) {
                    if (v < 1 || v > 9 || seen[v]) {
                        ok = false;
                        break;
                    }
                    seen[v] = 1;
                }
                if (!ok) continue;
                if (a + b + c != 15) continue;
                if (d + e + f != 15) continue;
                if (g + h + k != 15) continue;
                if (a + d + g != 15) continue;
                if (b + e + h != 15) continue;
                if (c + f + k != 15) continue;
                if (a + e + k != 15) continue;
                if (c + e + g != 15) continue;
                ans++;
            }
        }
        return ans;
    }
};