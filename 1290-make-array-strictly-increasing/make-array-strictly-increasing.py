class Solution:
    def makeArrayIncreasing(Self,a,b):
        b=sorted(set(b))
        c=[-10**18]+a+[10**18]
        d=len(c)
        e=[10**9]*d
        e[0]=0
        for f in range(1,d):
            if c[f-1]<c[f]:
                e[f]=e[f-1]
            g=bisect_left(b,c[f])
            h=min(f-1,g)
            for i in range(1,h+1):
                if c[f-i-1]<b[g-i]:
                    e[f]=min(e[f],e[f-i-1]+i)
        return -1 if e[-1] >=10**9 else e[-1]

    # def makeArrayIncreasing(self, arr1: List[int], arr2: List[int]) -> int:
        