class Solution {
public:
    int minFlips(string s) {
        int n = s.size(), cnt = 0, ans;
        for(int i=0;i<n;i++) cnt += s[i] != "01"[i&1];
        ans = min(cnt, n-cnt);
        for(int i=0;i<n;i++){
            cnt -= s[i] != "01"[i&1];
            cnt += s[i] != "01"[(i+n)&1];
            ans = min({ans,cnt,n-cnt});
        }
        return ans;
    }
};