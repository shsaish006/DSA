class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<int> bMin1(n + 2, INT_MAX), bMin2(n + 2, INT_MAX);

        // Step 1 & 2: Normalize and fill bMin1 and bMin2
        for (auto& pair : conflictingPairs) {
            int a = min(pair[0], pair[1]);
            int b = max(pair[0], pair[1]);
            if (b < bMin1[a]) {
                bMin2[a] = bMin1[a];
                bMin1[a] = b;
            } else if (b < bMin2[a]) {
                bMin2[a] = b;
            }
        }

        // Step 3–4: Traverse in reverse and calculate valid subarrays + potential gain
        long long res = 0;
        int ib1 = n;
        int b2 = INT_MAX;
        vector<long long> delCount(n + 2, 0);

        for (int i = n; i >= 1; --i) {
            if (bMin1[ib1] > bMin1[i]) {
                b2 = min(b2, bMin1[ib1]);
                ib1 = i;
            } else {
                b2 = min(b2, bMin1[i]);
            }

            int end = min(bMin1[ib1], n + 1);
            res += end - i;

            int recoverable = min({b2, bMin2[ib1], n + 1}) - min(bMin1[ib1], n + 1);
            delCount[ib1] += recoverable;
        }

        // Step 5: Best gain by removing one conflict
        long long maxGain = 0;
        for (int i = 1; i <= n; ++i) {
            maxGain = max(maxGain, delCount[i]);
        }

        return res + maxGain;
    }
};
