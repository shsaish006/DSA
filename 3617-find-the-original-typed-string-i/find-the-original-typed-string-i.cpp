// class Solution {
// public:
//     int possibleStringCount(string word) {
//         int f = 0;
//         int i = 0;
//         while (i < word.size()) {
//             char current = word[i];
//             f++;
//             while (i < word.size() && word[i] == current) {
//                 i++;
//             }
//         }
//         return f;
//     }
// };


class Solution {
public:
    int possibleStringCount(string word) {
        int f = 1;
        for (int i = 1; i < word.size(); ++i) {
            if (word[i] == word[i - 1]) {
                f++;
            }
        }
        return f;
    }
};
