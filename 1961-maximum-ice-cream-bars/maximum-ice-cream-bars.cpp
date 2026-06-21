class Solution {
public:
    int maxIceCream(vector<int>& a, int c) {
        sort(a.begin(), a.end());
        int ans = 0;
        for (int x : a) {
            if (c < x) break;
            c -= x;
            ans++;
        }
        return ans;
    }
};