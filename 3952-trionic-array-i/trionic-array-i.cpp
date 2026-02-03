class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size(),i=1,f=0;
        while(i<n &&nums[i]>nums[i-1]) i++;
        if(i==1||i==n) return false;
        while(i<n&&nums[i]<nums[i-1]) i++,f=1;
        if(!f|| i==n) return false;
        while(i<n&&nums[i]>nums[i-1]) i++;
        return i==n;
        
    }
};