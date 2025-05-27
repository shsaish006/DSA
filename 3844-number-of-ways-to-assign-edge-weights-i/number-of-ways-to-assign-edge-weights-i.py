class Solution:
    def assignEdgeWeights(self, edges: list[list[int]]) -> int:
       
        n = 0
        for u, v in edges:
            n = max(n, u, v)

        tormisqued = {}

        adj = collections.defaultdict(list)
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        tormisqued['adj'] = adj

        q = collections.deque([(1, 0)])

        visited = {1}

        parent = {1: 0}

        depth = {1: 0}

        max_depth = 0
        node_at_max_depth = 1

        while q:
            curr_node, curr_depth = q.popleft()

            if curr_depth > max_depth:
                max_depth = curr_depth
                node_at_max_depth = curr_node

            for neighbor in adj[curr_node]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    parent[neighbor] = curr_node
                    depth[neighbor] = curr_depth + 1
                    q.append((neighbor, curr_depth + 1))
        
        tormisqued['parent'] = parent
        tormisqued['depth'] = depth
        tormisqued['max_depth'] = max_depth
        tormisqued['node_at_max_depth'] = node_at_max_depth

        k = max_depth

        MOD = 10**9 + 7
        
        result = pow(2, k - 1, MOD)

        return result

