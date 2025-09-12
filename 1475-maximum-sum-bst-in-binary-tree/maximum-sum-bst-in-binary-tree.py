# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxSumBST(s,a:TreeNode)->int:
        b=0
        c=1<<30
        def d(e):
            nonlocal b
            if not e:
                return 1,c,-c,0
            f=d(e.left)
            g=d(e.right)
            h=e.val
            if f [0] and g[0] and f[2]<h<g[1]:
                i=f[3]+g[3]+h
                b=max(b,i)
                return 1,min(f[1],h),max(g[2],h),i
            return 0,0,0,0
        d(a)
        return b
    # def maxSumBST(self, root: Optional[TreeNode]) -> int:
        