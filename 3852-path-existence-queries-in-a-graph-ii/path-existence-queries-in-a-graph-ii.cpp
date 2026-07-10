class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& a, int x, vector<vector<int>>& q) {
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) v.push_back({a[i],i});
        sort(v.begin(),v.end());

        vector<vector<int>> f(n,vector<int>(20));
        for(int i=n-1,j=n-1;i>=0;i--){
            while(v[j].first-v[i].first>x) j--;
            f[v[i].second][0]=v[j].second;
            for(int k=1;k<20;k++) f[v[i].second][k]=f[f[v[i].second][k-1]][k-1];
        }

        vector<int> ans;
        for(auto &e:q){
            int i=e[0],j=e[1];
            if(a[i]>a[j]) swap(i,j);
            if(i==j){ ans.push_back(0); continue; }
            if(a[i]==a[j]){ ans.push_back(1); continue; }

            int d=0;
            for(int k=19;k>=0;k--)
                if(a[f[i][k]]<a[j]) d|=1<<k,i=f[i][k];

            ans.push_back(a[f[i][0]]<a[j]?-1:d+1);
        }
        return ans;
    }
};