from math import inf
class Graph:

    def __init__(s, a: int, b: List[List[int]]):
        s.a=a
        s.b=[[inf]*a for _ in range(a)]
        for c,d,e in b:
            s.b[c][d]=e
        

    def addEdge(s, a: List[int]) -> None:
        c,d,e =a
        s.b[c][d]=e
        

    def shortestPath(s, a: int, b: int) -> int:
        c=[inf]* s.a
        c[a]=0
        d=[False]* s.a
        for _ in range(s.a):
            e=-1
            for f in range(s.a):
                if not d[f] and (e==-1 or c[e]>c[f]):
                    e=f
            d[e]=True
            for f in range(s.a):
                c[f]=min(c[f],c[e]+s.b[e][f])
        return -1 if c[b]==inf else c[b]

        


# Your Graph object will be instantiated and called as such:
# obj = Graph(n, edges)
# obj.addEdge(edge)
# param_2 = obj.shortestPath(node1,node2)