class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(int x:nums){
            if(x==2){
                ans.push_back(-1);
            }else{
                int val=((~x)&(x+1))>>1;
                ans.push_back(x^val);
            }
        }
        return ans;
    }
};