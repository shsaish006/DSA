class Solution:
    def minLights(self, lights: list[int]) -> int:
        n=len(lights)
        vals=[0]*(n+1)
        for i in range(n):
            val=lights[i]
            if val:
                vals[max(0,i-val)]+=1
                vals[min(n,i+val+1)]-=1
        curr=0
        for i in range(n):
            curr+=vals[i]
            vals[i]=curr 
        dp=[-1]*(n+4)
        def dfs(i):
            if i>=n:
                return 0 
            if dp[i]!=-1:
                return dp[i]
            if vals[i]:
                dp[i]=dfs(i+1)
            else:
                dp[i]=1+dfs(i+3)
            return dp[i]
        return dfs(0)
        