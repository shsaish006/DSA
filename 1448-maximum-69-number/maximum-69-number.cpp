class Solution {
public:
    int maximum69Number(int num) {
        int a = num / 1000;
        int b = (num / 100) % 10;
        int c = (num / 10) % 10;
        int d = num % 10;
        if (a == 6) a = 9;
        else if (b == 6) b = 9;
        else if (c == 6) c = 9;
        else if (d == 6) d = 9;

        return a * 1000 + b * 100 + c * 10 + d;
    }
};
