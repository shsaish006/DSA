class RLEIterator:
    def __init__(self,a):
        self.a=a
        self.b=0
        self.c=0


    # def __init__(self, encoding: List[int]):
        

    # def next(self, n: int) -> int:
    def next(self,d):
        while self.b<len(self.a) and d>0:
            e=self.a[self.b]-self.c
            if d>e:
                d-=e
                self.b+=2
                self.c=0
            else:
                self.c+=d
                return self.a[self.b+1]
        return -1

        


# Your RLEIterator object will be instantiated and called as such:
# obj = RLEIterator(encoding)
# param_1 = obj.next(n)