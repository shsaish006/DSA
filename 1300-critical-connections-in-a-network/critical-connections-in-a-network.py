class Solution:
    def criticalConnections(self,n,a):
        def b(c,d):
            nonlocal e
            e+=1
            f[c]=g[c]=e
            for h in i[c]:
                if h==d:
                    continue
                if not f[h]:
                    b(h,c)
                    g[c]=min(g[c],g[h])
                    if g[h]>f[c]:
                        j.append([c,h])
                else:
                    g[c]=min(g[c],f[h])
        i=[[] for _ in range(n)]
        for k,l in a:
            i[k].append(l)
            i[l].append(k)
        f=[0]*n
        g=[0]*n
        e=0
        j=[]
        b(0,-1)
        return j
    # def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        