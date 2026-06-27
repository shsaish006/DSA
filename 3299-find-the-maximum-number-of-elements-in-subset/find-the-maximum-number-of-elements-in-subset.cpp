class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int> mp;
        for(int x:nums) mp[x]++;
        int ans=mp[1]-(mp[1]%2==0);
        mp.erase(1);
        for(unordered_map<long long,int>::iterator it=mp.begin();it!=mp.end();it++){
            long long v=it->first;
            int len=0;
            while(mp.count(v)&&mp[v]>1){
                len+=2;
                v*=v;
            }
            len+=mp.count(v)?1:-1;
            ans=max(ans,len);
        }
        return ans;
    }
};