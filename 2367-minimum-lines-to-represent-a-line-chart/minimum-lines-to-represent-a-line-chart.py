from itertools import pairwise
class Solution:
    def minimumLines(s,a):
        a.sort()
        b,c=0,1
        d=0
        for(e,f),(g,h) in pairwise(a):
            i,j=g-e, h-f
            if c*i !=b*j:
                d+=1
            b,c=i,j
        return d
    # def minimumLines(self, stockPrices: List[List[int]]) -> int:
        