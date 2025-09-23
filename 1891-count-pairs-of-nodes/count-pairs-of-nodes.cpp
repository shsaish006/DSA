class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> cnt(n,0);
        map<pair<int,int>, int> g;
        for(auto &e:edges){
            int a=e[0]-1, b=e[1]-1;
            if(a>b) swap(a,b);
            cnt[a]++ ; cnt[b]++;
            g[{a,b}]++;
        }
        vector<int> s=cnt;
        sort(s.begin(),s.end());
        vector<int> ans(queries.size(),0);
        for(int i=0;i<queries.size();i++){
            int t =queries[i];
            for(int j=0;j<n;j++){
                int x=s[j];
                int k=upper_bound(s.begin()+j+1,s.end(),t-x)-s.begin();
                ans[i]+=n-k;
            }
            for(auto &aa:g){
                int a=aa.first.first, b=aa.first.second, v=aa.second;
                if(cnt[a]+cnt[b]>t && cnt[a]+cnt[b]-v<=t) ans[i]--;
            }
        }
        return ans;
        
    }
};