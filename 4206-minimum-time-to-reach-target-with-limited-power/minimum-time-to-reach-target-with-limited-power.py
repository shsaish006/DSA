from heapq import *
class Solution:
    def minTimeMaxPower(self, n: int, edges: List[List[int]], power: int, cost: List[int], source: int, target: int) -> List[int]:
        g=[[] for _ in range(n)]
        for a,b,d in edges:
            g[a].append((b,d))
        dp={(source,power):0}
        h=[(0,source,power)]
        while h:
            d,u,r=heappop(h)
            if dp.get((u,r),1<<60)!=d or r<cost[u]:
                continue 
            aa=r-cost[u]
            for v,w in g[u]:
                bb=d+w 
                if bb<dp.get((v,aa),1<<60):
                    dp[(v,aa)]=bb 
                    heappush(h,(bb,v,aa))
        ans=[(v,x[1]) for x,v in dp.items() if x[0]==target]
        if not ans:
            return [-1,-1]
        t=min(x[0] for x in ans)
        r=max(x[1] for x in ans if x[0]==t )
        return [t,r]
        # return [-1,-1] if not ans else list(min(ans))