import collections
class Solution:
    def uniquePaths(self, a):
        b=len(a)
        c=len(a[0])
        # d=[[0]*c for _ in range(b)]
        # e=[]
        d=[]
        for _ in range(b):
            d.append([0]*c)
        e=[]
        for _ in range(b):
            e.append([(-2,-2)]*c)
        f=[]
        for _ in range(b):
            f.append([(-2,-2)]*c)
        g=10**9+7
        def h(i,j,k):
            l=e if k==0 else f
            if l[i][j][0]!=-2:
                return l[i][j]
            m=i
            n=j
            while True:
                if k==0:
                    o=m
                    p=n+1
                else:
                    o=m+1
                    p=n
                if not (0<=o<b and 0<=p<c):
                    l[i][j]=(-1,-1)
                    return -1,-1
                if a[o][p]==0:
                    l[i][j]=(o,p)
                    return o,p
                if k==0:
                    m=o+1
                    n=p
                    k=1
                else:
                    m=o
                    n=p+1
                    k=0
                if not (0<=m <b and 0<=n <c):
                    l[i][j]=(-1,-1)
                    return -1,-1
                while 0<=m<b and 0<=n<c and a[m][n]==1:
                    if k==0:
                        m+=1
                        k=1
                    else:
                        n+=1
                        k=0
                    if not (0<=m <b and 0<=n<c):
                        l[i][j]=(-1,-1)
                        return -1,-1
                l[i][j]=(m,n)
                return m,n

        d[0][0]=1
        for i in range(b):
            for j in range(c):
                if d[i][j]==0:
                    continue
                if i==b-1 and j==c-1:
                    continue
                q,r=h(i,j,0)
                if q!=-1:
                    d[q][r]=(d[q][r]+d[i][j])%g
                s,t=h(i,j,1)
                if s!=-1:
                    d[s][t]=(d[s][t]+ d[i][j])%g
        return d[b-1][c-1]
                    
        
        