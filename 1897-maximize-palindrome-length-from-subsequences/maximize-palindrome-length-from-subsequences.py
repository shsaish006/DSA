class Solution:
    def longestPalindrome(self, a: str, b: str) -> int:
        s=a+b 
        n,m=len(s),len(a)
        dp=[[0]* n for _ in range(n)]
        ans=0 
        for i in range(n-1,-1,-1):
            dp[i][i]=1
            for j in range(i+1,n):
                dp[i][j]=dp[i+1][j-1]+2 if s[i]==s[j] else max(dp[i+1][j], dp[i][j-1])
                if s[i]==s[j] and i<m <=j:
                    ans=max(ans, dp[i][j])
        return ans
#  asked in google interview