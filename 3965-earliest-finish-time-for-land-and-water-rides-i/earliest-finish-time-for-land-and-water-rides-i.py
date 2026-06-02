class Solution:
    def earliestFinishTime(self,a,b,c,d):
        e=len(a)
        f=len(c)
        g=float('inf')
        for h in range(e):
            # for i in range(f):
            j=a[h]+b[h]
            for i in range(f):
                k=max(j,c[i])+d[i]
                g=min(g,k)
                # k=max(j,c[i])
        for i in range(f):
            j=c[i]+d[i]
            for h in range(e):
                
                k=max(j,a[h])+b[h]
                # l=k+d[i]
                # g=min(g,l)
                # m=c[i]+d[i]
            # for i in range(f):
            #     j=c[i]+d[i]
                # j=max(a[h],c[i])
                # k=j+b[h]+d[i]
                g=min(g,k)
        return g
    # def earliestFinishTime(self, landStartTime: List[int], landDuration: List[int], waterStartTime: List[int], waterDuration: List[int]) -> int:
        