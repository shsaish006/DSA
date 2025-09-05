class AllOne:

    def __init__(self):
        self.a={}
        self.b={}

        

    def inc(self, x: str) -> None:
        if x in self.a:
            c=self.a[x]
            self.b[c].remove(x)
            if not self.b[c]:
                del self.b[c]
            self.a[x]=c+1
        else:
            self.a[x]=1
        self.b.setdefault(self.a[x],set()).add(x)
        

    def dec(self,x: str) -> None:
        c=self.a[x]
        self.b[c].remove(x)
        if not self.b[c]:
            del self.b[c]
        if c==1:
            del self.a[x]
        else:
            self.a[x]=c-1
            self.b.setdefault(c-1,set()).add(x)

        

    def getMaxKey(self) -> str:
        if not self.a:
            return ""
        m=max(self.b)
        return next(iter(self.b[m]))

        

    def getMinKey(self) -> str:
        if not self.a:
            return ""
        m=min(self.b)
        return next(iter(self.b[m]))
        


# Your AllOne object will be instantiated and called as such:
# obj = AllOne()
# obj.inc(key)
# obj.dec(key)
# param_3 = obj.getMaxKey()
# param_4 = obj.getMinKey()