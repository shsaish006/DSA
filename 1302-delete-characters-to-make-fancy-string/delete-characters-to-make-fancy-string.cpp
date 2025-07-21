class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        int count = 1;  // counts consecutive characters

        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                ++count;
            } else {
                count = 1;
            }

            if (count < 3) {
                ans += s[i - 1];
            }
        }

        // Always include the last character
        ans += s.back();
        return ans;
    }
};
