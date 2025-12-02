class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const int mod = 1000000007;
        vector<int> ys;
        ys.reserve(points.size());
        for (auto &p : points) ys.push_back(p[1]);
        sort(ys.begin(), ys.end());
        long long ans = 0, s = 0, c = 1;
        for (int i = 1; i <= ys.size(); i++) {
            if (i < ys.size() && ys[i] == ys[i-1]) {
                c++;
            } else {
                long long t = c * (c - 1) / 2;
                ans = (ans + s * t) % mod;
                s = (s + t) % mod;
                c = 1;
            }
        }
        return (int)ans; }};