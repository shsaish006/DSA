# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def balanceBST(self,root):
        nums=[]
        def sai(a):
            if not a:return 
            sai(a.left)
            nums.append(a.val)
            sai(a.right)
        sai(root)
        from collections import deque 
        d=deque(nums)
        def build(n):
            if n<=0: return None 
            l=build(n//2)
            a=TreeNode(d.popleft())
            r=build(n-n//2-1)
            a.left=l
            a.right=r
            return a
        return build(len(nums))
    # def balanceBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        