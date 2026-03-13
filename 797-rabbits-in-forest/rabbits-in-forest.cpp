class Solution {
public:
    int numRabbits(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int a=0,cnt=0,val=-1;

        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                if(cnt>0) a+=val+1;
                val=nums[i];
                cnt=0;
            }
            cnt++;
            if(cnt==val+1){
                a+=val+1;
                cnt=0;
            }
        }

        if(cnt>0) a+=val+1;
        return a;
    }};