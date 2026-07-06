from collections import Counter
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        c= Counter(s1)
        m= len(s1)
        return any(Counter(s2[i:i+m]) == c for i in range(len(s2)-m+1))
        # return any(Counter(s2[i:i+len(s1)])==c for i in range(len(s2)-len(s2)+1))