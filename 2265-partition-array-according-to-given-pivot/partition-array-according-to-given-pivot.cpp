class Solution {
public:
    vector<int> pivotArray(vector<int>& a, int p) {
        vector<int> b;
        for (int x : a) if (x < p) b.push_back(x);
        for (int x : a) if (x == p) b.push_back(x);
        for (int x : a) if (x > p) b.push_back(x);
        return b;
    }
};