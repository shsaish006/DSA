class Solution {
public:
    string crackSafe(int n, int k) {
        int mod=1;
        for(int i=1;i<n;i++) mod*=10;
        unordered_set<int> vis;
        string ans; 
        function<void(int)> dfs=[&](int u){
            for(int x=0;x<k;x++){
                int e=u*10+x;
                if(!vis.count(e)){
                    vis.insert(e);
                    int v=e%mod;
                    dfs(v);
                    ans.push_back('0'+x);
                }
            }
        };
        dfs(0);
        ans.append(n-1,'0');
        return ans;
        
    }
};