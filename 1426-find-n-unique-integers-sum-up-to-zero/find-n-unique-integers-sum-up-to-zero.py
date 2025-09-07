class Solution:
    def sumZero(self, a: int) -> List[int]:
        b=[0]*a
        c=0
        for d in range(1,a//2+1):
            b[c]=d
            c+=1
            b[c]=-d
            c+=1
        return b
        