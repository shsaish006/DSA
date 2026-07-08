class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& p, vector<vector<int>>& q) {
        vector<vector<bool>> f(n, vector<bool>(n));
        for(vector<int> &i:p) f[i[0]][i[1]]=1;
        for(int k=0;k<n;k++)
        for(int i=0; i<n;i++)
        if(f[i][k])
        for(int j=0;j<n;j++)
        f[i][j] = f[i][j] || f[k][j];
        vector<bool> ans;
        for(vector<int> &i:q) ans.push_back(f[i[0]][i[1]]);
        return ans;
        
    }
};
//  ans is true if there is no direct or indirect path
//  adjacent matrix crete karke store karenge direct pre
//  use floyd warshall indirect prequ
// start karnege direct preq then use evry course as bridge to discover indirect preq