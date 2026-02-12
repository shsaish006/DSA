class Solution:
    def longestBalanced(self, S: str) -> int:
        a = b = c = 0
        history = {("abc",0,0):0, ("ab",0,0):0, ("bc",0,0):0, ("ca",0,0):0, ("a",0,0):0, ("b",0,0):0, ("c",0,0):0}
        total = 0
        for i, char in enumerate(S, 1):
            if char == 'a': a += 1
            if char == 'b': b += 1
            if char == 'c': c += 1
            states = [("abc",a-b,a-c),("ab",a-b,c),("bc",b-c,a),("ca",c-a,b),("a",b,c),("b",c,a),("c",a,b)]
            for s in states:
                total = max(total, i - (history[s] if s in history else history.setdefault(s, i)))
        return total