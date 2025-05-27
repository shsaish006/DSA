class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m=rowSum.size(),n=colSum.size();
        vector<vector<int>> arr(m,vector<int>(n,0));
        for(int i=0;i<rowSum.size();i++){
            for(int j=0;j<colSum.size();j++){
                arr[i][j]=min(rowSum[i],colSum[j]);
                rowSum[i]-=arr[i][j];
                colSum[j]-=arr[i][j];
            }
        }
        return arr;

        
    }
};