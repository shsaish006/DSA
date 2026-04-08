# from typimg import List
# from collections import defaultdict
class Solution:
    def xorAfterQueries(self, a: List[int], b: List[List[int]]) -> int:
        m=10**9+7
        n=len(a)
        # g=0
        # for i in range(n):
        #     f=1
            
        f=[1]*n
        # sai=defaultdict(list)
        # for i in range(n):
        #     for k in range(!,n+1):
        #         sai[k].append(i%k)
        for q in b:
            l,r,k,v=q
            
            # if l<=i<=r and (i-l)%k==0:
            #     f=f*v%m
        
            i=l
            # for i in range(l,r+1):
            #     if(i-1)%k==0:
            #         f[i]=f[i]*v%m
            while i<=r:
                f[i]=f[i]*v%m
                i+=k
        # f=1
        g=0
        for i in range(n):
            # f=f*d[i]%m
            g^=a[i]*f[i]%m
        return g
        