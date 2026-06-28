class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& a) {
        sort(a.begin(), a.end());
        int x = 0;
        for (int &i : a) x = min(i, x + 1);
        return x;
    }
};