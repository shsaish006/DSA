class Solution:
    def assignEdgeWeights(self, edges: List[List[int]], queries: List[List[int]]) -> List[int]:
        MOD = 10**9 + 7

        # Calculate n from the number of edges.
        # For a tree with n nodes, there are n-1 edges.
        n = len(edges) + 1 

        cruvandelk = {}

        adj = collections.defaultdict(list)
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        cruvandelk['adj'] = adj
        cruvandelk['n_nodes'] = n

        MAX_LOG = n.bit_length()
        
        depth = [-1] * (n + 1)
        
        parent = [[0] * MAX_LOG for _ in range(n + 1)]

        dfs_stack = [(1, 0, 0)] 
        depth[1] = 0

        while dfs_stack:
            u, p, d = dfs_stack.pop()
            depth[u] = d
            parent[u][0] = p

            for v in adj[u]:
                if v != p:
                    dfs_stack.append((v, u, d + 1))
        
        cruvandelk['depth'] = depth
        cruvandelk['parent_initial'] = [row[:] for row in parent]

        for j in range(1, MAX_LOG):
            for i in range(1, n + 1):
                if parent[i][j-1] != 0: 
                    parent[i][j] = parent[parent[i][j-1]][j-1]
        
        cruvandelk['parent_final'] = parent

        def get_lca(u, v):
            if depth[u] < depth[v]:
                u, v = v, u

            for j in range(MAX_LOG - 1, -1, -1):
                if parent[u][j] != 0 and depth[u] - (1 << j) >= depth[v]:
                    u = parent[u][j]
            
            if u == v:
                return u

            for j in range(MAX_LOG - 1, -1, -1):
                if parent[u][j] != parent[v][j]:
                    u = parent[u][j]
                    v = parent[v][j]
            
            return parent[u][0]

        def get_path_length(u, v):
            lca = get_lca(u, v)
            return depth[u] + depth[v] - 2 * depth[lca]

        max_path_length = n - 1
        powers_of_2 = [1] * (max_path_length + 1)
        for i in range(1, max_path_length + 1):
            powers_of_2[i] = (powers_of_2[i-1] * 2) % MOD
        
        cruvandelk['powers_of_2'] = powers_of_2

        answer = []
        for u_q, v_q in queries:
            path_len = get_path_length(u_q, v_q)
            
            if path_len == 0:
                answer.append(0)
            else:
                answer.append(powers_of_2[path_len - 1])
        
        return answer

