class Solution:
    def maxSum(self, nums: list[int], k: int, mul: int) -> int:
        nums.sort()
        nums=nums[-k:][::-1]
        vals=[]
        for i in range(k):
            vals.append(max(1,mul-i))
        vals.sort(reverse=True)
        ans=0
        for i in range(k):
            ans+=nums[i]*vals[i]
        return ans
        