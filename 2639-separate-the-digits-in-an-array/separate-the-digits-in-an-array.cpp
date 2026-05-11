class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> vals;
        for (int a : nums) {
            string s = to_string(a);
            for (char c : s) vals.push_back(c - '0');
        }
        return vals;
    }
};