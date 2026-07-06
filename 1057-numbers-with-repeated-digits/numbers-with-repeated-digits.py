from functools import cache 
class Solution:
    def numDupDigitsAtMostN(self, n: int) -> int:
        s=str(n)
        @cache
        def f(i,m,l,t):
            if i==len(s): return not l 
            u=int(s[i]) if t else 9 
            return sum (
                f(i+1, m if l and d==0 else m| 1<<d, l and d==0, t and d==u)
                for d in range(u+1)
                if l and d==0 or not (m>> d &1)
            )
        return n-f(0,0,1,1)
        