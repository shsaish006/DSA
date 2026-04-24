class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int a = 0, b = 0;

        for (char c : moves) {
            if (c == 'L') a--;
            else if (c == 'R') a++;
            else b++;
        }

        return abs(a) + b;
    }
};