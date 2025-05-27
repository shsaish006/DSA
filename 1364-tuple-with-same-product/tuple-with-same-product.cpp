class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int res=0,n=nums.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int ss=nums[i]*nums[j];
                res+=8*(mpp[ss]);
                mpp[ss]++;
            }
        }
        return res;
        
    }
};