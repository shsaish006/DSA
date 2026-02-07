class Solution {
public:
    int minimumDeletions(string s) {
        int a = 0;
        int b = 0;
        for (char c : s) {
            if (c == 'b') {
                b++;
            } else {
                a = min(a + 1, b);
            }
        }
        return a;
    }
};
