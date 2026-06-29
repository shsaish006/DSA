class Solution:
    def maxSubarraySum(self, nums: List[int], k: int) -> int:
        def f(g):
            a=b=c=d=-10**18 
            for x in nums:
                y=g(x)
                o,p,q=a,b,c 
                a,b,c=max(x,o+x), max(y,o+y,p+y),max(p+x,q+x)
                d=max(d,a,b,c)
            return d
        return max(f(lambda x: x*k),f(lambda x:x//k if x>=0 else -((-x)//k)))
        