class Solution {
public:
    bool rotateString(string s, string goal) {
        int a = s.size(), b = goal.size();
        if (a != b) return false;

        string temp = goal + "#" + s + s;
        vector<int> nums(temp.size());

        for (int i = 1; i < temp.size(); i++) {
            int j = nums[i - 1];
            while (j && temp[i] != temp[j]) j = nums[j - 1];
            if (temp[i] == temp[j]) j++;
            nums[i] = j;
            if (nums[i] == b) return true;
        }

        return false;
    }
};