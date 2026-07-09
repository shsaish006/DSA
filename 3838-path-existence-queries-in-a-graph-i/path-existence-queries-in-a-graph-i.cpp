class Solution {
public:
//  nums= a
//  maxDiff =d
//  queries = q
    vector<bool> pathExistenceQueries(int n, vector<int>& a, int d, vector<vector<int>>& q) {
        vector<int> g(n);
        for(int i=1, c=0; i<n;i++) g[i]=c+=a[i]- a[i-1]>d;
        vector<bool> ans;
        for(auto &i:q) ans.push_back(g[i[0]]==g[i[1]]);
        return ans;
        
    }
};