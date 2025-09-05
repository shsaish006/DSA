class Solution:
    def canPartition(self,a):
        b,c=divmod(sum(a),2)
        if c:
            return False
        d=[False]*(b+1)
        d[0]=True
        for e in a:
            for f in range(b,e-1,-1):
                d[f]=d[f] or d[f-e]
        return d[b]
    # def canPartition(self, nums: List[int]) -> bool:
        