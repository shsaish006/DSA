class Solution:
    def cherryPickup(self,a):
        b=len(a)
        c=[[[-10**9]*b for _ in range(b)] for _ in range((b<<1) -1)]
        c[0][0][0]=a[0][0]
        for d in range(1,(b<<1)-1):
            for e in range(b):
                for f in range(b):
                    g,h=d-e, d-f
                    if g<0 or h<0 or g>=b or h>=b or a[e][g]<0 or a[f][h]<0:
                        continue
                    i=a[e][g]
                    if e!=f:
                        i+= a[f][h]
                    for j in (e-1,e):
                        for k in (f-1,f):
                            if j>=0 and k>=0:
                                c[d][e][f] =max(c[d][e][f], c[d-1][j][k]+i)
        return max(0,c[-1][-1][-1])

    # def cherryPickup(self, grid: List[List[int]]) -> int:
        