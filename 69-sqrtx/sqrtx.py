class Solution:
    def mySqrt(self, x: int) -> int:
        a,b=0,x
        while a<=b:
            c=(a+b)//2
            if c*c<=x:
                a=c+1
            else:
                b=c-1
        return b