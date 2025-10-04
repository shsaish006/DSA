class Solution {
public:
    int maxArea(vector<int>& H) {
        int n = H.size(), ans = 0;
        for (int l = 0, r = n - 1; l < r;) {
            ans = max(ans, min(H[l], H[r]) * (r - l));
            H[l] < H[r] ? ++l : --r;
        }
        return ans;
    }
};
