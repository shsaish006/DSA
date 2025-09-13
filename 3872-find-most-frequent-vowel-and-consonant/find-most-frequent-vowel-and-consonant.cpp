class Solution {
public:
    int maxFreqSum(string s) {
        int cnt[26] = {};
        for (char c : s) cnt[c - 'a']++;
        int a = 0, b = 0;
        for (int i = 0; i < 26; i++) {
            if (string("aeiou").find('a' + i) != string::npos) a = max(a, cnt[i]);
            else b = max(b, cnt[i]);
        }
        return a + b;}};
