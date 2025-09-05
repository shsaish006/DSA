class Solution:
    def numberOfArithmeticSlices(self,a):
        b=c=0
        d=3000
        for e in range(1,len(a)):
            f=a[e]-a[e-1]
            if f==d:
                c+=1
            else:
                d=f
                c=0
            b+=c
        return b
    # def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        