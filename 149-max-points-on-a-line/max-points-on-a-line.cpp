class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), ans = 1;
        for (int i = 0; i < n; i++) {
            unordered_map<long double,int> mp;
            int dup = 0, cur = 0;
            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                if (dx == 0 && dy == 0) { dup++; continue; }
                long double slope = dx == 0 ? DBL_MAX : (long double)dy / dx;
                cur = max(cur, ++mp[slope]);
            }
            ans = max(ans, cur + dup + 1);
        }
        return ans;}};
