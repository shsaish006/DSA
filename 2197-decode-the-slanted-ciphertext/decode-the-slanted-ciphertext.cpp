class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (encodedText.empty()) return "";
        int a = encodedText.size();
        int b = a / rows;
        string s;
        for (int i = 0; i < b; i++) {
            int j = i;
            while (j < a) {
                s += encodedText[j];
                j += b + 1;
                if (j >= a) break;
                if (j % b < i) break;
            }
        }
        while (!s.empty() && s.back() == ' ') s.pop_back();
        return s;
    }
};