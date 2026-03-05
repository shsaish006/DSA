class Solution {
public:
    int numSpecial(vector<vector<int>>& a) {
        int m=a.size(), n=a[0].size(), s=0;
        vector<int> r(m), c(n);
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) r[i]+=a[i][j], c[j]+=a[i][j];
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) s+=a[i][j]&&r[i]==1&&c[j]==1;
        return s;
    }
};