import bisect
class Solution:
    def minRemoval(self, a: List[int], b: int) -> int:
        a.sort()
        c=len(a)
        # d=c-1
        # e=0
        
        d=0
        # for f in reversed(range(c)):
        #     while a[d]>a[f]*b
        # e=max(e,d-f+1)
        for e in range(c):
            # f=e
            # while f<c and a[f]*a[e])
            f=a[e]*b
            g=bisect.bisect_right(a,f)
            # f+=1
            d=max(d,g-e)
        return c-d
        
        