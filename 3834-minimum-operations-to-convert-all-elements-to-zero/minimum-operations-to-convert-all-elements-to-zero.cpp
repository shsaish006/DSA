class Solution {
public:
    int minOperations(vector<int>& a) {
        int n = a.size(), ans = 0;
        vector<int> v;
        for (int x : a) {
            while (!v.empty() && v.back() > x) {
                v.pop_back();
                ans++;
            }
            if (x && (v.empty() || v.back() != x)) v.push_back(x);
        }
        return ans + (int)v.size();
    }
};