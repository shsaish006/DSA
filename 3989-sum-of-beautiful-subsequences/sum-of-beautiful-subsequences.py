MOD=10**9+7
from typing import List
class Solution:
    def totalBeauty(self,a:List[int])->int:
        b=len(a)
        c=max(a)
        d=[[] for _ in range(c+1)]
        for i,v in enumerate(a,1):
            d[v].append(i)
        e=list(range(c+1))
        for f in range(2,c+1):
            if e[f]==f:
                for g in range(f,c+1,f):
                    e[g]=e[g]//f*(f-1)
        h=[0]*(b+2)
        i=[]
        j=0
        def add(k,x):
            while k<=b:
                if h[k]==0:i.append(k)
                h[k]+=x
                if h[k]>=MOD: h[k]-=MOD
                k+=k & -k
        def sumq(k):
            l=0
            while k>0:
                l+=h[k]
                if l>=MOD: l-=MOD
                k-=k& -k
            return l
        for k in range(1,c+1):
            m=0
            for n_ in range(k,c+1,k):
                o=d[n_]
                if not o: continue
                p=[]
                for q in o:
                    r=sumq(q-1)
                    s=r+1
                    if s>=MOD : s-=MOD
                    p.append((q,s))
                    m+=s
                    if m>=MOD: m-=MOD
                for q,s in p:
                    add(q,s)
            if m:
                j+=e[k]*m
                if j>=MOD : j%=MOD
            for q in i: h[q]=0
            i.clear()
        return j%MOD

        # M=10**9+7
    #     b=max(a)
    #     c=[[] for _ in range(b+1)]
    #     for d in range(1,b+1):
    #         for e in range(d,b+1,d):
    #             c[e].append(d)
    #     d=list(range(b+1))
    #     for e in range(2,b+1):
    #         if d[e]==e:
    #             for f in range(e,b+1,e):
    #                 d[f]=d[f]//e*(e-1)
    #     e=[0]*(b+1)
    #     f=[0]*(b+1)
    #     g=[[] for _ in range(b+1)]
    #     for h in a:
    #         for i in c[h]:
    #             if not e[i]:
    #                 g[i]=[0]*(b//i+3)
    #                 e[i]=1
    #             j=h//i
    #             k=1
    #             if j>1:
    #                 k=(k+sum(g[i][:j]))%M
    #             g[i][j]=(g[i][j]+k)%M
    #             f[i]=(f[i]+k)%M
    #     s=0
    #     for i in range(1,b+1):
    #         if e[i]:
    #             s=(s+d[i]*f[i])%M
    #     return s

    # # def totalBeauty(self, nums: List[int]) -> int:
        