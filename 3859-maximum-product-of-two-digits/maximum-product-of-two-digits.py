class Solution:
    def maxProduct(s, a: int) -> int:
        b = c = 0
        while a > 0:
            a, d = divmod(a, 10)
            if d > b:
                b, c = d, b
            elif d > c:
                c = d
        return b * c
