class Solution {
public:
    int maxSideLength(vector<vector<int>>& a, int t) {
        int m=a.size(),n=a[0].size();
        vector<vector<int>> s(m+1,vector<int>(n+1));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i-1][j-1];
            }
        }
        int l=0,r=min(m,n);
        while(l<r){
            int mid=(l+r+1)>>1,ok=0;
            for(int i=0;i+mid<=m && !ok;i++){
                for(int j=0;j+mid<=n && !ok;j++){
                    int x=i+mid,y=j+mid;
                    int v=s[x][y]-s[i][y]-s[x][j]+s[i][j];
                    if(v<=t) ok=1;
                }
            }
            if(ok) l=mid;
            else r=mid-1;
        }
        return l;
    }
};