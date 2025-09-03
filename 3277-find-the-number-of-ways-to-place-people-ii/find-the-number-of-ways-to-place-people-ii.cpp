class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int maxY = INT_MIN;
            for (int j = i + 1; j < n; ++j) {
                if (points[j][1] <= points[i][1]) {
                    if (points[j][1] > maxY) {
                        ans++;
                        maxY = points[j][1];
                    }
                }
            }
        }
        return ans;
    }
};