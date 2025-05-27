class Solution {
public:
    #define ll long long
    int lengthAfterTransformations(string s, int t) {
        int MOD=1e9+7;
        int ans=s.size();
        vector<ll> freq(26,0);
        for(auto && x : s){
            freq[x-'a']++;
        }

        for(int i=1;i<=t;++i){
            vector<ll> temp(26,0);
            for(int c=0;c<25;++c){
                if(freq[c]==0) continue;
                temp[c+1]=freq[c];
                temp[c+1]%=MOD;
            }
            if(freq[25]){
                ans+=freq[25];
                ans%=MOD;
                temp[0]+=(freq[25]%MOD);
                temp[1]+=(freq[25]%MOD);
            }
            freq=temp;
        }
        return ans;
    }
};
