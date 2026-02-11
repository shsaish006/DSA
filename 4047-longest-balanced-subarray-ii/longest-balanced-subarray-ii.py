# from typing import List
# class Solution:
#     def longestBalanced(self, vals: List[int]) -> int:
#         sai=vals
#         n=len(sai)
#         # cnt={}
#         # val=0
#         # a=set()
#         # b=set()
#         # fo={0:-1}
#         # cd=0
#         l=0
#         # upd=0
#         # que=0
#         # val=0
#         # for idx1,a in enumerate(sai):
#         #     if a%2==0:
#         #         if a not in cnt:
#         #             cnt[a]=1
#         #             upd+=1
#         for idx1 in range(n):
#             even=0
#             odd=0
            
#         #     c=sai[idx1]
#         #     if c%2==0:
#             for idx2 in range(idx1,n):
#                 c=sai[idx2]
#                 if c%2==0:
#                     even|=1<<c
#                 else:
#                     odd|=1<<c
#         #         a.add(c)
#         #     else:
#         #         b.add(c)
#         #     # cnt=set()
#         #     # temp=set()
#         #     cd=len(a)-len(b)
#                 if bin(even).count('1')==bin(odd).count('1'):
#                     l=max(l,idx2-idx1+1)
#         #     if cd in fo:
#         #         l=max(l,idx1-fo[cd])
#         #     # for idx2 in range(idx1,n):
#         #     #     a=sai[idx2]
#         #         # if diff in curr:
#         #         #     val=max(val,idx1-curr[diff])
#         #     else:
#         #         fo[cd]=idx1
#         #         # else:
#         #         #     curr[diff]-idx1
#         #         # if a%2==0:
#         #         #     cnt.add(a)
#         #         # else:
#         #         #     if a  not in temp:
#         #         #         temp[a]=1
#         #         #         que+=1
#         #         # diff=(que-upd,len(cnt)-len(temp))
#         # #         else:
#         # #             temp.add(a)
#         # #         if len(cnt)==len(temp):
#         # #             val=max(val,idx2-idx1+1)
#         return l
        
        #  AI HELP + editorial But i solve it in weekend...
from typing import List

class SegmentTree:
    def __init__(self, n):
        self.mn = [0] * (4 * n)
        self.mx = [0] * (4 * n)
        self.lazy = [0] * (4 * n)
        self.build(1, 0, n)

    def build(self, u, l, r):
        if l == r:
            return
        m = (l + r) // 2
        self.build(u * 2, l, m)
        self.build(u * 2 + 1, m + 1, r)

    def push(self, u):
        if self.lazy[u]:
            for v in (u * 2, u * 2 + 1):
                self.mn[v] += self.lazy[u]
                self.mx[v] += self.lazy[u]
                self.lazy[v] += self.lazy[u]
            self.lazy[u] = 0

    def update(self, u, l, r, ql, qr, val):
        if ql <= l and r <= qr:
            self.mn[u] += val
            self.mx[u] += val
            self.lazy[u] += val
            return
        self.push(u)
        m = (l + r) // 2
        if ql <= m:
            self.update(u * 2, l, m, ql, qr, val)
        if qr > m:
            self.update(u * 2 + 1, m + 1, r, ql, qr, val)
        self.mn[u] = min(self.mn[u * 2], self.mn[u * 2 + 1])
        self.mx[u] = max(self.mx[u * 2], self.mx[u * 2 + 1])

    def query(self, u, l, r, target):
        if self.mn[u] > target or self.mx[u] < target:
            return -1
        if l == r:
            return l
        self.push(u)
        m = (l + r) // 2
        left = self.query(u * 2, l, m, target)
        if left != -1:
            return left
        return self.query(u * 2 + 1, m + 1, r, target)


class Solution:
    def longestBalanced(self, nums: List[int]) -> int:
        n = len(nums)
        st = SegmentTree(n)

        last = {}
        pref = 0
        ans = 0

        for i in range(1, n + 1):
            x = nums[i - 1]
            val = 1 if x & 1 else -1

            if x in last:
                st.update(1, 0, n, last[x], n, -val)
                pref -= val

            last[x] = i
            st.update(1, 0, n, i, n, val)
            pref += val

            pos = st.query(1, 0, n, pref)
            if pos != -1:
                ans = max(ans, i - pos)
        return ans