# import heapq
# class Solution:
#     # import sys
#     # a=sys.stdin.read().split()
#     # b=0
#     # c=int(a[b]); b+=1
#     # for _ in range(c):
#     #     d=int(a[b]); e=int(a[b+1]); f=int(a[b+2]); b+=3
#     #     g=[]
#     # def minCost(self, grid: List[List[int]], k: int) -> int:
#     def minCost(self,a,b:int)->int:
        
#     # def minCost(m,k,g):
#         c,d=len(a),len(a[0])
#         # inf=10**18
#         # d=[[[inf]*(k+1) for _ in range(b)] for _ in range(a)]
#         # d[0][0][0]=g[0][0]
#         # q=[(g[0][0],0,0,0)]
#         e=1<<60
#         f=c*d
#         def g(h,i):
#             return h*d+i
#         j=[]
#         for h in range(c):
#             for i in range(d):
#                 j.append((a[h][i],g(h,i)))
#         j.sort()
#         # while q:
#         #     c,x,y,u=heapq.heappop(q)
#         #     if c>d[x][y][u]:
#         #         continue
#         #     if x==a-1 and y==b-1:
#         #         return c
#         k,l=[],[]
#         # k=[]
#         h=0
#         # while k:
#         #     if l!=j[m][n][o]:
#         #         continue
#         #     if m==d-1 and n==e-1:
#         #         print(1)
#         #         break
#         #     i
#         while h<f:
#             m=j[h][0]
#             n=[]
#             while h<f and j[h][0]==m:
#                 n.append(j[h][1])
#                 h+=1
#                 # if n+1<e:
#                 #     p=l+g[m][n+1]
#                 #     if p<j[m][n+1][o]:
#                 #         j[m][n+1][o]=p
#                 #         heapq.heappush(k,(p,m,n+1,o))
#             l.append(m)
#             k.append(n)
#         k.reverse()
#         l.reverse()
        
#         #     for dx,dy in [(-1,0),(0,1)]:
#         #         nx,ny=x+dx,y+dy
#         #         if 0<=nx<a and 0<=ny<b:
#         #             nc=c+g[nx][ny]
#         #             if nc<d[nx][ny][u]:
#         #                 d[nx][ny][u]=nc
#         #                 heapq.heappush(q,(nc,nx,ny,u))
#         def o(p):
#             # if o<f:
#             #     if l<j[m][n][o+1]
#             q=p[:]
#             for h in range(c):
#                 for i in range(d):
#                     r=q[g(h,i)]
#                     if r>=e:
#                         continue
#                     if i+1<d:
#                         s=a[h][i+1]
#                         t=r+s
#                         u=g(h,i+1)
#                         if t<q[u]:
#                             q[u]=t
#                     if h+1<c:
#                         s=a[h+1][i]
#                         t=r+s
#                         u=g(h+1,i)
#                         if t<q[u]:
#                             q[u]=t
#             return q
    
                        
#         #     if u<k:
#         #         for i in range(a):
#         #             for j in range(b):
#         #                 if g[i][j]<=g[x][y]:
#         #                     if c<d[i][j][u+1]:
#         #                         d[i][j][u+1]=c
#         #                         heapq.heappush(q,(c,i,j,u+1))
#         v=[e]*f
#         v[0]=a[0][0]
#         w=e
#         for x in range(b+1):
#             y=o(v)
#             w=min(w,y[g(c-1,d-1)])
#             if x==b:
#                 break
#             z=[e]*f
#             aa=e
#             for ab in range(len(k)):
#                 for ac in k[ab]:
#                     aa=min(aa,y[ac])
#                 for ac in k[ab]:
#                     z[ac]=aa
#             v=z
#         return -1 if w>=e else int(w)
#         # return -1
        
class Solution:
    def minCost(self, grid: list[list[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        points = [(i, j) for i in range(m) for j in range(n)]
        points.sort(key=lambda p: grid[p[0]][p[1]])
        costs = [[float("inf")] * n for _ in range(m)]
        for t in range(k + 1):
            minCost = float("inf")
            j = 0
            for i in range(len(points)):
                minCost = min(minCost, costs[points[i][0]][points[i][1]])
                if (
                    i + 1 < len(points)
                    and grid[points[i][0]][points[i][1]]
                    == grid[points[i + 1][0]][points[i + 1][1]]
                ):
                    i += 1
                    continue
                for r in range(j, i + 1):
                    costs[points[r][0]][points[r][1]] = minCost
                j = i + 1
            for i in range(m - 1, -1, -1):
                for j in range(n - 1, -1, -1):
                    if i == m - 1 and j == n - 1:
                        costs[i][j] = 0
                        continue
                    if i != m - 1:
                        costs[i][j] = min(
                            costs[i][j], costs[i + 1][j] + grid[i + 1][j]
                        )
                    if j != n - 1:
                        costs[i][j] = min(
                            costs[i][j], costs[i][j + 1] + grid[i][j + 1]
                        )
        return costs[0][0]