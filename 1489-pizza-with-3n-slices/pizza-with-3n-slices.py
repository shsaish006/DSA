class Solution:
    def maxSizeSlices(s, a: List[int]) -> int:
        def b(c:list[int])->int:
            d=len(c)
            e=[[0]* (f+1) for _ in range(d+1)]
            for g in range(1,d+1):
                for h in range(1,f+1):
                    e[g][h]=max(e[g-1][h],(e[g-2][h-1] if g>=2 else 0)+c[g-1])
            return e[d][f]
        f=len(a)//3
        g,h=b(a[:-1]),b(a[1:])
        return max(g,h)


        