class Solution {
public:
    int maxDotProduct(vector<int>& nums, vector<int>& vals) {
        int a=nums.size(),b=vals.size();
        int i,j,val;
        vector<vector<int>> o(a+1, vector<int>(b+1, -1000000000));
        for(i=1;i<=a;i++){
            for(j=1;j<=b;j++){
                val=nums[i-1]*vals[j-1];
                o[i][j]=max(o[i-1][j],o[i][j-1]);
                o[i][j]=max(o[i][j],max(0,o[i-1][j-1])+val);
            }
        }
        return o[a][b];
    }};