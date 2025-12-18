class Solution {
public:
    long long maxProfit(vector<int>& vals, vector<int>& o, int k) {
        int n = vals.size();
        vector<long long> s(n + 1), t(n + 1);
        for (int i = 1; i <= n; i++) {
            long long a = vals[i - 1];
            long long b = o[i - 1];
            s[i] = s[i - 1] + a * b;
            t[i] = t[i - 1] + a;
        }
        long long curr = s[n];
        for (int i = k; i <= n; i++) {
            curr = max(curr, s[n] - (s[i] - s[i - k]) + (t[i] - t[i - k / 2]));
        }
        return curr;
    }
};