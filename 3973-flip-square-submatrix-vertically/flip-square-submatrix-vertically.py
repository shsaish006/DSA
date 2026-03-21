class Solution:
    def reverseSubmatrix(self,a,b,c,d):
        e=0
        # e=list(zip(*a[b:b+d]))
        # e=[list(f[::-1]) for f in e]
        while e<d//2:
            f=0
        # for f in range(d):
        #     a[b+f][c:c+d]=e[f]
            while f<d:
                a[b+e][c+f],a[b+d-1-e][c+f]=a[b+d-1-e][c+f],a[b+e][c+f]
                f+=1
            e+=1
        return a
    # def reverseSubmatrix(self, grid: List[List[int]], x: int, y: int, k: int) -> List[List[int]]:
        