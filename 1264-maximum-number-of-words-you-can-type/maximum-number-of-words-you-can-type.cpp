class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> broken(26, false);
        for (char c : brokenLetters) broken[c - 'a'] = true;
        
        int ans = 0;
        string word;
        for (int i = 0; i <= text.size(); i++) {
            if (i == text.size() || text[i] == ' ') {
                bool ok = true;
                for (char c : word) {
                    if (broken[c - 'a']) { ok = false; break; }
                }
                if (ok) ans++;
                word.clear();
            } else {
                word += text[i];
            }
        }return ans; }};
