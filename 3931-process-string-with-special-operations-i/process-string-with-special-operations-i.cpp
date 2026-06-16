class Solution {
public:
    string processStr(string s) {
        int n=s.size();
        vector<string> dp(n+1);
        for(int i=0;i<n;i++){
            dp[i+1]=dp[i];
            char c=s[i];
            if(isalpha(c)) dp[i+1]+=c;
            else if(c=='*' && !dp[i+1].empty()) dp[i+1].pop_back();
            else if(c=='#') dp[i+1]+=dp[i+1];
            else if(c=='%') reverse(dp[i+1].begin(),dp[i+1].end());
        }

        return dp[n];
    }
};