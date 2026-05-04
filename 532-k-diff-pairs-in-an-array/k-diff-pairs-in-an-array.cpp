class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k<0) return 0;
        sort(nums.begin(), nums.end());
        int a=nums.size(), b=0, c=1, d=0;
        while(c<a){
            long long s=1LL*nums[c]-nums[b];
            if(b==c || s<k){
                c++;
            
            // if(b==c || nums[c]-nums[b]<k){
            //     c++;
            
        }
        else if (s>k){
            b++;
            
            // else if(nums[c]-nums[b]>k){
            // b++;
        }else{
            d++;
            b++;
            c++;
            while(b<a && nums[b]==nums[b-1]) b++;
            while(c<a && nums[c]==nums[c-1]) c++;
        }
        }
        return d;
        
    }
};