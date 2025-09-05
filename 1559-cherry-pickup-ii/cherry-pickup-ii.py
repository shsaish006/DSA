class Solution:
    def cherryPickup(Self,a):
        b,c=len(a),len(a[0])
        d=[[[-1]* c for _ in range(c)] for _ in range(b)]
        d[0][0][c-1]=a[0][0]+a[0][c-1]
        for e in range(1,b):
            for f in range(c):
                for g in range(c):
                    h=a[e][f]+(0 if f==g else a[e][g])
                    for i in (f-1,f,f+1):
                        for j in (g-1,g,g+1):
                            if 0<=i<c and 0<=j<c and d[e-1][i][j]!=-1:
                                d[e][f][g]=max(d[e][f][g],d[e-1][i][j]+h)
        return max(d[-1][i][j] for i in range(c) for j in range(c))
    # def cherryPickup(self, grid: List[List[int]]) -> int:
        