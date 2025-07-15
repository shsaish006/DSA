class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3) return false;

        bool has_vowel = false;
        bool has_consonant = false;

        for (char c : word) {
            if (isalpha(c)) {
                char lower = tolower(c);
                if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                    has_vowel = true;
                } else {
                    has_consonant = true;
                }
            } else if (!isdigit(c)) {
                return false; // non-alphanumeric character
            }
        }

        return has_vowel && has_consonant;
    }
};

