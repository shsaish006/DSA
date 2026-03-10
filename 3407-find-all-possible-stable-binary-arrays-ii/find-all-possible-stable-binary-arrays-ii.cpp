// class Solution {
// public:
//     int numberOfStableArrays(int a, int b, int c) {
//         int mod = 1e9+7;

//         vector dp(a+1, vector(b+1, vector(c+1, vector<int>(2,0))));

//         if(a>0) dp[1][0][1][0] = 1;
//         if(b>0) dp[0][1][1][1] = 1;

//         for(int i=0;i<=a;i++){
//             for(int j=0;j<=b;j++){
//                 for(int k=1;k<=c;k++){

//                     if(dp[i][j][k][0]){
//                         if(i+1<=a && k+1<=c)
//                             dp[i+1][j][k+1][0] = (dp[i+1][j][k+1][0] + dp[i][j][k][0])%mod;

//                         if(j+1<=b)
//                             dp[i][j+1][1][1] = (dp[i][j+1][1][1] + dp[i][j][k][0])%mod;
//                     }

//                     if(dp[i][j][k][1]){
//                         if(j+1<=b && k+1<=c)
//                             dp[i][j+1][k+1][1] = (dp[i][j+1][k+1][1] + dp[i][j][k][1])%mod;

//                         if(i+1<=a)
//                             dp[i+1][j][1][0] = (dp[i+1][j][1][0] + dp[i][j][k][1])%mod;
//                     }

//                 }
//             }
//         }

//         int ans = 0;

//         for(int k=1;k<=c;k++){
//             ans = (ans + dp[a][b][k][0])%mod;
//             ans = (ans + dp[a][b][k][1])%mod;
//         }

//         return ans;
//     }
// };
class Solution {
public:
    static const int mod = 1000000007;

    int numberOfStableArrays(int a, int b, int c) {

        vector<vector<int>> d0(a+1, vector<int>(b+1,0));
        vector<vector<int>> d1(a+1, vector<int>(b+1,0));

        for(int i=0;i<=a;i++){
            for(int j=0;j<=b;j++){

                if(i==0 && j==0) continue;

                if(i==0){
                    if(j<=c) d1[i][j]=1;
                    continue;
                }

                if(j==0){
                    if(i<=c) d0[i][j]=1;
                    continue;
                }

                long long v0 = d0[i-1][j];
                v0 = (v0 + d1[i-1][j])%mod;

                if(i>c)
                    v0 = (v0 - d1[i-c-1][j] + mod)%mod;

                d0[i][j] = v0;

                long long v1 = d0[i][j-1];
                v1 = (v1 + d1[i][j-1])%mod;

                if(j>c)
                    v1 = (v1 - d0[i][j-c-1] + mod)%mod;

                d1[i][j] = v1;
            }
        }

        return (d0[a][b] + d1[a][b])%mod;
    }
};