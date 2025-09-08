class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int ans = 0, sum = 0;
        for (int i = 0; i < flips.size(); i++) {
            sum += flips[i];
            if (sum == (long long)(i + 1) * (i + 2) / 2) ans++;
        }
        return ans;
    }
};
