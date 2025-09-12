class Solution:
    def minEnd(s, a: int, b: int) -> int:
        a -= 1
        c = b
        for d in range(31):
            if not (b >> d & 1):
                c |= (a & 1) << d
                a >>= 1
        c |= a << 31
        return c
