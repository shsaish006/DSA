class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n=customers.size();
        long long CT=0,TWT=0;
        for(int i=0;i<n;++i){
            int arrival=customers[i][0];
            int timeTaken=customers[i][1];
            if(CT<arrival){
                CT=arrival;
            }
            CT+=timeTaken;
            TWT+=CT-arrival;
        }
        return(double) TWT/n;
    }
};
