class Solution {
public:
    int maxSumDivThree(vector<int>& a) {
        vector<int> b(3,-1e9);
        b[0] = 0;
        for (int c : a) {
            vector<int> d(b);
            for (int e = 0; e < 3; e++) {
                d[(e + c % 3) % 3] =max(d[(e + c % 3) % 3], b[e] + c);
            }
            b = d;
        }
        return b[0];
    }
};
