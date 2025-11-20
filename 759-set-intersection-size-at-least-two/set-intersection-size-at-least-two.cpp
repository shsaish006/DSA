class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), [&](vector<int>& s, vector<int>& o) {
            if (s[1] == o[1]) return s[0] > o[0];
            return s[1] < o[1];
        });




        int s = -1, e = -1, ans = 0;
        for (auto &v : a) {
            int x = v[0], y = v[1];
            if (x <= s) continue;
            if (x > e) {
                ans += 2;
                s = y - 1;
                e = y;
            } else {

                
                ans += 1;
                s = e;
                e = y;
            }
        }
        return ans;
    }
};