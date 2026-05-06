class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& nums) {
        int a = nums.size(), b = nums[0].size();
        vector<vector<char>> vals(b, vector<char>(a, '.'));

        for (int i = 0; i < a; i++) {
            int idx = b - 1;

            for (int j = b - 1; j >= 0; j--) {
                if (nums[i][j] == '*') {
                    vals[j][a - 1 - i] = '*';
                    idx = j - 1;
                } else if (nums[i][j] == '#') {
                    vals[idx][a - 1 - i] = '#';
                    idx--;
                }
            }
        }
return vals; }};