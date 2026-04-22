class Solution {
public:
    vector<string> twoEditWords(vector<string>& nums, vector<string>& vals) {
        vector<string> ans;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < vals.size(); j++) {
                int cnt = 0;
                for (int k = 0; k < nums[i].size(); k++) {
                    if (nums[i][k] != vals[j][k]) cnt++;
                    if (cnt > 2) break;
                }
                if (cnt <= 2) {
                    ans.push_back(nums[i]);
                    break;
                }
            }
        }
        return ans;
    }
};