# TC: O(nlog n)
# SC: O(n)
#  a=tree
from typing import List
class Solution:
    def outerTrees(self, a: List[List[int]]) -> List[List[int]]:
        def b(c,d,e):
            f,g,h=a[c],a[d],a[e]
            return (g[0]-f[0])*(h[1]-g[1])-(g[1]-f[1])*(h[0]-g[0])
        c=len(a)
        if c<4:
            return a
        a.sort()
        d=[0]
        e=[0]*c
        for f in range(1,c):
            while len(d)>1 and b(d[-2],d[-1],f)<0:
                e[d.pop()]=0
            e[f]=1
            d.append(f)
        g=len(d)
        for f in range(c-2,-1,-1):
            if e[f]:
                continue
            while len(d)>g and b(d[-2],d[-1],f)<0:
                d.pop()
            d.append(f)
        d.pop()
        return [a[f] for f in d]

        