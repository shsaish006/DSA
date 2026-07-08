class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>> g(n);
        vector<int> in(n), ans;
        queue<int> q;
        for(auto &i:p) g[i[1]].push_back(i[0]), in[i[0]]++;
        for(int i=0;i<n;i++)
        if(!in[i]) q.push(i);
        while(q.size()){
            int u=q.front(); q.pop();
            ans.push_back(u);
            for(int v: g[u])
            if(!--in[v]) q.push(v);
        }
        return ans.size()==n ? ans: vector<int>{};
    }
};
//  we have to return the topo order and find the valid order of course
//  store the processed nodes in a vector
//  diff rom course schedule 1 is there we have to return true false check if all courses are finished or not and count the processed nodes
//  yaha hardum course lenge with no rem preq... uske bbaad update karenge count of course jo depend hain uss per
//  indegree ko hum no of preq after taking it reduce the count of all course jo depend hain ussper and jab indegree 0 ho jaye 0 avail akrenge next