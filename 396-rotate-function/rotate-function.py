class Solution:
    def maxRotateFunction(self, nums: List[int]) -> int:
        a = len(nums)
        s = sum(nums)
        curr = sum(i * nums[i] for i in range(a))
        val = curr

        for i in range(a - 1, 0, -1):
            curr += s - a * nums[i]
            val = max(val, curr)

        return val