from typing import List
from functools import lru_cache
class Solution:
    def asteroidsDestroyed(self, p: int, nums: List[int]) -> bool:
        nums.sort()
        n = len(nums)
        @lru_cache(None)
        def dp(idx, m):
            if idx == n:
                return True
            if m < nums[idx]:
                return False
            return dp(idx + 1, m + nums[idx])
        return dp(0, p)