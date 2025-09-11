from sortedcontainers import SortedList
from math import inf
class Solution:
    def minimumDistance(s,a):
        b=SortedList()
        c=SortedList()
        for d,e in a:
            b.add(d+e)
            c.add(d-e)
        f=inf
        for d , e in a:
            b.remove(d+e)
            c.remove(d-e)
            f=min(f,max(b[-1]-b[0],c[-1]-c[0]))
            b.add(d+e)
            c.add(d-e)
        return f

    # def minimumDistance(self, points: List[List[int]]) -> int:
        