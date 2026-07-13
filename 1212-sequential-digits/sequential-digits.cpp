class Solution {
public:
    vector<int> sequentialDigits(int a, int b) {
        vector<int> c;
        for (int i = 1; i < 9; i++) {
            int d = i;
            for (int j = i + 1; j < 10; j++) {
                d = d * 10 + j;
                if (d >= a && d <= b) c.push_back(d);
            }
        }
        for (int i = 0; i < c.size(); i++)
            for (int j = i + 1; j < c.size(); j++)
                if (c[i] > c[j]) swap(c[i], c[j]);
        return c;
    }
};