class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> a(52);
        for (int i = 0; i < s1.size(); i += 2) {
            a[s1[i] - 'a']++;
            a[s2[i] - 'a']--;
        }
        for (int i = 1; i < s1.size(); i += 2) {
            a[26 + s1[i] - 'a']++;
            a[26 + s2[i] - 'a']--;
        }
        for (int i = 0; i < 52; ++i) {
            if (a[i]) return false;
        }
        return true;
    }
};