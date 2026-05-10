class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int a=nums.size();
        vector<int> vals(a,-1e9);
        vals[0]=0;

        for(int i=0;i<a;i++)
            for(int j=i+1;j<a;j++)
                if(abs(nums[i]-nums[j])<=target)
                    vals[j]=max(vals[j],vals[i]+1);

        return vals.back()<0?-1:vals.back();
    }
};