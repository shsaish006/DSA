from itertools import accumulate

class Solution:
    def minChanges(s, a: list[int], b: int) -> int:
        c = [0] * (b + 2)
        d = len(a)
        for e in range(d // 2):
            f, g = min(a[e], a[-e - 1]), max(a[e], a[-e - 1])
            c[0] += 1
            c[g - f] -= 1
            c[g - f + 1] += 1
            h = max(g, b - f) + 1
            c[h] -= 1
            c[h] += 2

        ans = d
        s = 0
        for x in c:
            s += x
            ans = min(ans, s)
        return ans
