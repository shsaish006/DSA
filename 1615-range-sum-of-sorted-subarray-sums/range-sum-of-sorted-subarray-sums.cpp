class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> vec;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                sum=0;
                for(int k=i;k<=j;k++) sum+=nums[k];
                vec.push_back(sum);
            }
        }
        sort(vec.begin(),vec.end());
        sum=0;
        int lim=1e9+7;
        for(int i=left-1;i<right;i++) sum=(sum%lim)+vec[i];
        return sum;

        
    }
};