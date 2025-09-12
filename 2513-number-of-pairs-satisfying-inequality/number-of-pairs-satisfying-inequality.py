class BIT:
    def __init__(s,n):
        s.n=n; s.c=[0]*(n+1)
    def low(x): return x&-x
    def add(s,x,d):
        while x<=s.n: s.c[x]+=d; x+=BIT.low(x)
    def sum(s,x):
        r=0
        while x: r+=s.c[x]; x-=BIT.low(x)
        return r

class Solution:
    def numberOfPairs(x,a,b,d):
        t=BIT(10**5)
        r=0
        for i,j in zip(a,b):
            v=i-j
            r+=t.sum(v+d+40000)
            t.add(v+40000,1)
        return r
