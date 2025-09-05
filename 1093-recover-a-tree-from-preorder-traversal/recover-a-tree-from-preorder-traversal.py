# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recoverFromPreorder(self, s: str) -> Optional[TreeNode]:
        a=[]
        b=0
        while b<len(s):
            c=0
            while b<len(s) and s[b]=='-':
                c+=1
                b+=1
            d=0
            while b<len(s) and s[b].isdigit():
                d=d*10+int(s[b])
                b+=1
            e=TreeNode(d)
            while len(a)>c:
                a.pop()
            if a:
                if not a[-1].left:
                    a[-1].left=e
                else:
                    a[-1].right=e
            a.append(e)
        return a[0] if a else None 
        