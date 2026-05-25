class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        
        int n=s.size();
        vector<int>pre(n+1),dp(n);
        dp[0]=pre[1]=1;
        for(int i=1;i<n;i++){
            int l=max(0,i-maxJump),r=i-minJump;
            if(s[i]=='0' && l<=r && pre[r+1]-pre[l])
                dp[i]=1;
            pre[i+1]=pre[i]+dp[i];
        }
        return dp[n-1];
    }
};