from math import inf 
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        m=inf 
        r=0
        for v in prices:
            r=max(r,v-m)
            m=min(m,v)
        return  r