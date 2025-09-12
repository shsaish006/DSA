from heapq import heappush, heappop
from bisect import bisect_right
class Solution:
    def kWeakestRows(s, a: List[List[int]], b: int) -> List[int]:
        c=len(a)
        d=len(a[0])
        e=[]
        for f in range(c):
            g=d- bisect_right(a[f][::-1],0)
            heappush(e,(g,f))
        h=[]
        for _ in range(b):
            h.append(heappop(e)[1])
        return h
        