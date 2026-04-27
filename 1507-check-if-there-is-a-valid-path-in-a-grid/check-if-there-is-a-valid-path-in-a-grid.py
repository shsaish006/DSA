class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
        from collections import deque
        a,b= len(grid), len(grid[0])
        d={
            1:[(0,-1), (0,1)],
            2:[(-1,0), (1,0)],
            3:[(0,-1), (1,0)],
            4:[(0,1),(1,0)],
            5:[(0,-1), (-1,0)],
            6:[(0,1), (-1,0)]
        }
        q=deque([(0,0)])
        s={(0,0)}
        while q:
            i,j=q.popleft()
            if i==a -1 and j ==b-1 :
                return True 
            for c, d1 in d[grid[i][j]]:
                x,y= i+c, j+d1 
                if 0<=x<a and 0<=y< b and (x,y) not in s:
                    if(-c,-d1) in d[grid[x][y]]:
                        s.add((x,y))
                        q.append((x,y))
        return False
        