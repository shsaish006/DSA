from bisect import insort
class Solution:
    def filterOccupiedIntervals(self, a: List[List[int]], b: int, c: int) -> List[List[int]]:
        d=[]
        for x in a:insort(d,x)
        s=[]
        for e,f in d:
            if s and e<=s[-1][1]+1:s[-1][1]=max(s[-1][1],f)
            else:s.append([e,f])
        d=[]
        for e,f in s:
            if f<b or e>c:d.append([e,f])
            else:
                if e<b:d.append([e,b-1])
                if f>c:d.append([c+1,f])
        return d
        