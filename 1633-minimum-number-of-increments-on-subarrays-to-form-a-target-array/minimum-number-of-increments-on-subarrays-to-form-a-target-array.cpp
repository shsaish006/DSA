class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int f = 0, prev = 0;
        for (int x : target) {
            if (x > prev) f += x - prev;
            prev = x;
        }
        return f;
    }
};