class Solution:
    def fac(s,a):
        b=[]
        c=2
        while c*c<=a:
            if a%c==0:
                d=0
                while a%c==0:
                    a//=c
                    d+=1
                b.append((c,d))
            c+=1
        if a>1:
            b.append((a,1))
        return b
    def sai(s,a,b):
        c=1
        while b:
            if b&1:
                c*=a
            a*=a
            b>>=1
        return c
    def minDifference(s,a,b):
        c=s.fac(a)
        d=[1]*b
        e=[1]*b
        f=10**18
        def g(h):
            nonlocal f,d,e
            if h==len(c):
                i=min(e)
                j=max(e)
                k=j-i
                if k<f:
                    f=k
                    d=e[:]
                return 
            l,m=c[h]
            n=[0]* b
            def o(p,q):
                nonlocal e
                if p==b-1:
                    n[p]=q
                    r=e[:]
                    for u in range(b):
                        e[u]*=s.sai(l,n[u])
                    g(h+1)
                    e=r
                    return 
                for v in range(q+1):
                    n[p]=v
                    o(p+1,q-v)
            o(0,m)
        g(0)
        return [int(x) for x in d]
    # def minDifference(self, n: int, k: int) -> List[int]:
        