class Solution {
public:
    int largestAltitude(vector<int>& g) {
        vector<int> p(g.size() + 1);
        partial_sum(g.begin(), g.end(), p.begin() + 1);
        return *max_element(p.begin(), p.end());
    }
};