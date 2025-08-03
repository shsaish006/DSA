class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> positions, prefixSum(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            positions.push_back(fruits[i][0]);
            prefixSum[i + 1] = prefixSum[i] + fruits[i][1];
        }

        int res = 0;

        for (int x = 0; x <= k; ++x) {
            int left = startPos - x;
            int right = startPos + max(0, k - 2 * x);
            int i = lower_bound(positions.begin(), positions.end(), left) - positions.begin();
            int j = upper_bound(positions.begin(), positions.end(), right) - positions.begin();
            res = max(res, prefixSum[j] - prefixSum[i]);
        }

        for (int x = 0; x <= k; ++x) {
            int right = startPos + x;
            int left = startPos - max(0, k - 2 * x);
            int i = lower_bound(positions.begin(), positions.end(), left) - positions.begin();
            int j = upper_bound(positions.begin(), positions.end(), right) - positions.begin();
            res = max(res, prefixSum[j] - prefixSum[i]);
        }

        return res;
    }
};
