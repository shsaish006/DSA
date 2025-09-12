from heapq import heappush, heappop

class Solution:
    def maxSum(s, a: list[list[int]], b: list[int], c: int) -> int:
        d = []
        for e, f in zip(a, b):
            e.sort(reverse=True)
            for g in e[:f]:
                heappush(d, g)
                if len(d) > c:
                    heappop(d)
        return sum(d)
   