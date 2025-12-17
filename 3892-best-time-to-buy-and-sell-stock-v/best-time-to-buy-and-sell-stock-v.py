class Solution(object):
    def maximumProfit(self, prices, k):
        n=len(prices)
        if n<2 or k==0:
            return 0
        a=[0]*n
        for _ in range(1,k+1):
            b=[0]*n
            c=-2e18
            d=-2e18
            for i in range(1,n):
                e=a[i-2] if i>1 else 0
                c=max(c,e-prices[i-1])
                d=max(d,e+prices[i-1])
                f=max(prices[i]+c,-prices[i]+d)
                b[i]=max(b[i-1],f)
            a=b
        return a[-1]
        """
        :type prices: List[int]
        :type k: int
        :rtype: int
        """
        