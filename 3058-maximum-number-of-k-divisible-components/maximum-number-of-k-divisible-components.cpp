class Solution {
public:
    int l=0;
    long long dfs(vector<vector<int>>& graph,vector<int>&values,int node,int parent,int k){
        long long sum=values[node];
        for(int neighbor:graph[node]){
            if(neighbor!=parent){
                sum+=dfs(graph,values,neighbor,node,k);

            }
        }
        if(sum%k==0){
            l++;
            return 0;
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> graph(n);
        for(auto& edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);

        }
        dfs(graph,values,0,-1,k);
        return l;

        
    }
};