class Solution {
public:
    void rotate(vector<vector<int>>& nums) {
        int a = nums.size();

        for(int i=0;i<a;i++){
            for(int j=i+1;j<a;j++){
                swap(nums[i][j],nums[j][i]);
            }
        }

        for(int i=0;i<a;i++){
            reverse(nums[i].begin(),nums[i].end());
        }
    }
};