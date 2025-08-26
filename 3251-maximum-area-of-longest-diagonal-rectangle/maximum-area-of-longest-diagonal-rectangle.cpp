class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        pair<int, int> best = {0, 0};
        for (auto& d : dimensions) {
            int l = d[0], w = d[1];
            int diag2 = l * l + w * w;
            int area = l * w;
            best = max(best, {diag2, area});
        }
        return best.second;
    }
};
