class Solution {
public:
    int n,d;
    vector<int>dp,a;
    int dfs(int i){
        if(dp[i]) return dp[i];
        int ans=1;
        for(int j=i-1;j>=max(0,i-d)&&a[j]<a[i];j--){
            ans=max(ans,1+dfs(j));
        }
    for(int j=i+1;j<min(n,i+d+1)&&a[j]<a[i];j++){
            ans=max(ans,1+dfs(j));
        }
    return dp[i]=ans;
    }
    int maxJumps(vector<int>& arr, int k) {
        a=arr;
        d=k;
        n=a.size();
        dp.assign(n,0);

        int ans=1;
        for(int i=0;i<n;i++){
            bool ok=1;

            for(int j=i-1;j>=max(0,i-d);j--){
                if(a[j]>=a[i]){
                    ok=0;
                    break;
                }
                ans=max(ans,dfs(i));
            }

            for(int j=i+1;j<min(n,i+d+1);j++){
                if(a[j]>=a[i]) break;
                ans=max(ans,dfs(i));
            }
        }

        return ans;
    }
};