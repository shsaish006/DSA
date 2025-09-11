class T:
    def __init__(s):
        s.c=[None]*26
        s.e=False
    def i(s,w):
        n=s
        for x in w[::-1]:
            y=ord(x)-97
            if n.c[y] is None:

                n.c[y]=T()
            n=n.c[y]
        n.e=True
    def f(s,w):
        n=s
        for x in w[::-1]:
            y=ord(x)-97
            if n.c[y] is None:
                return False
            n=n.c[y]
            if n.e:
                return True
        return False
        
class StreamChecker:

    # def __init__(self, words: List[str]):
    def __init__(s,a):
        s.t=T()
        s.u=[]
        s.v=201
        for x in a:
            s.t.i(x)

        

    # def query(self, letter: str) -> bool:
    def query(s,x):
        s.u.append(x)
        return s.t.f(s.u[-s.v:])

        


# Your StreamChecker object will be instantiated and called as such:
# obj = StreamChecker(words)
# param_1 = obj.query(letter)