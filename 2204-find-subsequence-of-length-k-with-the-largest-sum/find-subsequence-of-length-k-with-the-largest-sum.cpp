#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& a, int b) {
        int c = a.size();
        vector<pair<int, int>> d;
        for (int e = 0; e < c; ++e) {
            d.push_back({a[e], e});
        }
        sort(d.begin(), d.end(), greater<pair<int, int>>());
        vector<pair<int, int>> f(d.begin(), d.begin() + b);
        sort(f.begin(), f.end(), [](auto& g, auto& h) {
            return g.second < h.second;
        });
        vector<int> i;
        for (auto& j : f) {
            i.push_back(j.first);
        }
        return i;
    }
};
