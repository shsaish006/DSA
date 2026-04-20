class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int a = colors.size(), b = 0;
        for (int i = 0; i < a; i++) {
            if (colors[i] != colors[0]) b = max(b, i);
            if (colors[i] != colors[a - 1]) b = max(b, a - 1 - i);
        }
        return b;
    }
};