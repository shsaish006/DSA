class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_set<int>set(nums1.begin(),nums1.end());
        for(int nums1:nums2){
            if(set.erase(nums1)){
                ans.push_back(nums1);
            }
        }
        return ans;
    }
};