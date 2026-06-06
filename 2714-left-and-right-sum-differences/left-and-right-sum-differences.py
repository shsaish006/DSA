from itertools import accumulate
class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        s = [0] + list(accumulate(nums))
        return [abs(s[idx] - (s[-1] - s[idx + 1])) for idx in range(len(nums))]