class Solution:
    def minSwaps(self, grid):
        n=len(grid)
        nums=[]
        for i in range(n):
            cnt=0
            for j in range(n-1,-1,-1):
                if grid[i][j]==0: cnt+=1
                else: break
            nums.append(cnt)
        val=0
        for i in range(n):
            j=i
            while j<n and nums[j]<n-1-i: j+=1
            if j==n: return -1
            val+=j-i
            while j>i:
                nums[j],nums[j-1]=nums[j-1],nums[j]
                j-=1
        return val