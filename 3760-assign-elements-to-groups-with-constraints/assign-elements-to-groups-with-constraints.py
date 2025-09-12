class Solution:
    def assignElements(s, a: list[int], b: list[int]) -> list[int]:
        c = max(a)
        d = [-1] * (c + 1)
        for e, f in enumerate(b):
            if f > c or d[f] != -1:
                continue
            for g in range(f, c + 1, f):
                if d[g] == -1:
                    d[g] = e
        return [d[h] for h in a]
