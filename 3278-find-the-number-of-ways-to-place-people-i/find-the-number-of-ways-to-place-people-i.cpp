class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && b[1] < a[1]);
        });
        int a = points.size();
        int b = 0;
        for (int c = 0; c < a; c++) {
            int d = points[c][1];
            int e = INT_MIN;
            for (int f = c + 1; f < a; f++) {
                int g = points[f][1];
                if (e < g && g <= d) {
                    e = g;
                    b++;
                }
            }
        }
        return b;}};
