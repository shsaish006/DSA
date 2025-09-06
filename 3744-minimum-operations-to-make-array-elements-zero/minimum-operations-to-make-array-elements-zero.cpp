#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        auto calc = [&](long long x) {
            long long res = 0, p = 1;
            int d = 1;
            while (p <= x) {
                long long len = min(p * 4 - 1, x) - p + 1;
                res += len * d;
                p *= 4;
                d++;
            }
            return res;
        };
        long long ans = 0;
        for (auto &q : queries) {
            long long l = q[0], r = q[1];
            long long s = calc(r) - calc(l - 1);
            long long mx = calc(r) - calc(r - 1);
            ans += max((s + 1) / 2, mx);
        }
        return ans;
    }
};
