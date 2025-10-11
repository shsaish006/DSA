#include <bits/stdc++.h>
using namespace std;
class Solution {
    unordered_map<int,int> cnt;
    vector<long long> f;
    vector<int> p,nx;
    int n;
    long long dfs(int i){
        if(i>=n)return 0;
        if(f[i])return f[i];
        long long a=dfs(i+cnt[p[i]]);
        long long b=1LL*p[i]*cnt[p[i]]+dfs(nx[i]);
        return f[i]=max(a,b);
    }
public:
    long long maximumTotalDamage(vector<int>& a){
        sort(a.begin(),a.end());
        p=a;n=a.size();
        f.resize(n);nx.resize(n);
        for(int i=0;i<n;i++){
            cnt[p[i]]++;
            nx[i]=upper_bound(p.begin()+i+1,p.end(),p[i]+2)-p.begin();
        }
        return dfs(0);
    }
};