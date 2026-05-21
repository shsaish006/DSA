class Solution {
public:
    // int dp(string &a, string &b){
    //     int n=min(a.size(), b.size()), cnt=0;
    //     for(int i=0;i<n && a[i] == b[i]; i++) cnt++;
    //     return cnt;
    // }
    int longestCommonPrefix(vector<int>& a, vector<int>& b) {
        unordered_set< int> s;
        int ans=0;
        for(int x:a) while(x) s.insert(x), x/=10;
        for(int x:b) while(x) {
            if(s.count(x))
            ans=max(ans,(int)to_string(x).size());
        x/=10;
        }
        // sort(a.begin(), a.end());
        // sort(b.begin(), b.end());
        // int ans=0;
        // for(int i=0;i<a.size(); i++){
        //     string s=to_string (a[i]);
        //     for(int j=0;j<b.size(); j++){
        //         string t=to_string(b[j]);
        //     int cnt=0, n=min(s.size(), t.size());
        //     while(cnt< n && s[cnt]== t[cnt])
        //     cnt++;
        //     ans=max(ans,cnt);
                // ans=max(ans,dp(s,t));
        //     }
        // }
        return ans;
        
    }
};


