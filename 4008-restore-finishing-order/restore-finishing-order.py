class Solution:
    def recoverOrder(self,a,b):
        n=len(a)
        c=[0]*(n+1)
        for x in b:
            c[x]=1
        d=[]
        for x in a:
            if c[x]:
                d.append(x)
        return d
    # def recoverOrder(self, order: List[int], friends: List[int]) -> List[int]:
        