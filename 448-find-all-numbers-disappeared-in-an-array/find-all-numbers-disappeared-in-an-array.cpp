class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n){
            int currentIdx=nums[i]-1;
            if(nums[currentIdx]==nums[i]) i++;        
            else swap(nums[i],nums[currentIdx]);
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1) ans.push_back(i+1);
        }
        return ans;
        
    }
};