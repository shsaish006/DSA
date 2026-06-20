class Solution:
    def goodIntegers(self, l: int, r: int, k: int) -> int:
        def f(n):
            if n<0: return 0 
            s=str(n)
            dp={(0,-1,1,1):1}
            for i in range(len(s)):
                nxt={}
                for (a,b,c,d), cnt in dp.items():
                    val=int(s[i]) if c else 9 
                    for e in range(val+1):
                        if d or abs(e-b)<=k:
                            tot=(i+1,e,c and e==val, d and e==0)
                            nxt[tot]=nxt.get(tot,0)+cnt 
                dp=nxt 
            return sum(dp.values())
        return f(r)-f(l-1)
        