class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        num=0 
        start,count=0,0 
        for i in range(1,len(s)):
            if s[i]!=s[i-1]:
                num+=min(count,i-start)
                count=i-start
                start=i 
        num+=min(count,len(s)-start)
        return num
        