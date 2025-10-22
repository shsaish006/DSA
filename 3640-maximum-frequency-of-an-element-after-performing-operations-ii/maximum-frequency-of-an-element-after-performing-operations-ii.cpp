class Solution {
public:
    int maxFrequency(vector<int>& a, int k, int o) {
        unordered_map<int,int> cnt;
        map<int,int> m;
        for(int x:a){
            cnt[x]++;
            m[x];
            m[x-k]++;
            m[x+k+1]--;
        }
        int s=0,ans=0;
        for(auto&[x,v]:m){
            s+=v;
            ans=max(ans,min(s,cnt[x]+o));
        }
        return ans;
    }};