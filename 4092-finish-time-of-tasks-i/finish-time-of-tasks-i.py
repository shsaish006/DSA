from functools import cache
class Solution:
    def finishTime(self, n: int, edges: List[List[int]], bT: List[int]) -> int:
        g=[[] for _ in range(n)]
        for a,b in edges:g[a].append(b)
        @cache 
        def f(a):
            if not g[a]: return bT[a]
            vals=[f(b) for b in g[a]]
            return 2*max(vals)-min(vals)+bT[a]
        return f(0)
        