class Solution {
public:
    int minimumDeleteSum(string a, string b) {
        int m=a.size(), n=b.size();
        int f[m+1][n+1];
        memset(f,0,sizeof f);
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=max(f[i-1][j],f[i][j-1]);
                if(a[i-1]==b[j-1]) f[i][j]=max(f[i][j],f[i-1][j-1]+a[i-1]);
            }
        }
        int s=0;
        for(char c:a) s+=c;
        for(char c:b) s+=c;
        return s-2*f[m][n];
    }
};