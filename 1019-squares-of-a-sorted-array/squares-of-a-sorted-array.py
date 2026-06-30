class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        return sorted(x * x for x in nums)
        #  Square every element in the array.
        # Since squaring can change the order  , sort the squared values.
        # Return the sorted squared array.