class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        auto it=unique(nums.begin(),nums.end());
        nums.resize(distance(nums.begin(),it));
        int n=nums.size();
        if(n<3){
            return nums[n-1];

        }
        int m=nums[n-3];
        return m;
        
    }
};