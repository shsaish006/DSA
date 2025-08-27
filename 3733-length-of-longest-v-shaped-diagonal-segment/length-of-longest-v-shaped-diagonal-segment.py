from functools import lru_cache

class Solution:
    def lenOfVDiagonal(self, grid):
        m, n = len(grid), len(grid[0])
        dirs = [1, 1, -1, -1, 1]

        @lru_cache(None)
        def dfs(i, j, k, cnt):
            x, y = i + dirs[k], j + dirs[k + 1]
            target = 2 if grid[i][j] == 1 else (2 - grid[i][j])
            if x < 0 or x >= m or y < 0 or y >= n or grid[x][y] != target:
                return 0
            res = dfs(x, y, k, cnt)
            if cnt > 0:
                res = max(res, dfs(x, y, (k + 1) % 4, 0))
            return 1 + res

        ans = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    for k in range(4):
                        ans = max(ans, dfs(i, j, k, 1) + 1)
        return ans
