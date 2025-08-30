from collections import Counter

class Solution:
    def partitionArray(self, a,b):
        c=len(a)
        if c%b!=0:
            return False
        d=c//b
        e=Counter(a)
        return all(f<=d for f in e.values())
        