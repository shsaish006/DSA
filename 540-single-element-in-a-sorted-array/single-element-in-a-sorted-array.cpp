class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int a=0, b=nums.size()-1;
        while(a<b){
            int c=a+(b-a)/2;
            if(c%2) c--;
            if(nums[c]==nums[c+1])
            a=c+2 ;
            else b=c;
        }
        return nums[a];
        
    }
};