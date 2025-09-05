# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getDirections(self,a,b,c):
        def d(e,f,g):
            if not e or e.val in(f,g):
                return e
            h=d(e.left,f,g)
            i=d(e.right,f,g)
            if h and i:
                return e
            return h or i
        def j(e,f,g):
            if not e:
                return False
            if e.val==f:
                return True
            g.append("L")
            if j(e.left,f,g):
                return True
            g[-1]="R"
            if j(e.right,f,g):
                return True
            g.pop()
            return False
        k=d(a,b,c)
        l=[]
        m=[]
        j(k,b,l)
        j(k,c,m)
        return "U"*len(l)+"".join(m)
    # def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
        