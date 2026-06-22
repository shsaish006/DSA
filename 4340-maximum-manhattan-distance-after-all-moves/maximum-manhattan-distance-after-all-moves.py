from collections import Counter
class Solution:
    def maxDistance(self, moves: str) -> int:
        c=Counter(moves)
        return abs(c['R']-c['L'])+abs(c['U']-c['D'])+c['_']
        