class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int j=i+nums[i];
            while(j<0) j+=n;
            while(j>=n) j-=n;
            ans[i]=nums[j];
        }
        return ans;
        
    }
};