class Solution {
public:
    vector<int> gcdValues(vector<int>& a, vector<long long>& b) {
        int n = *max_element(a.begin(), a.end());
        vector<int> c(n + 1);
        vector<long long> d(n + 1);
        for (int x : a) c[x]++;
        for (int i = n; i; i--) {
            long long s = 0;
            for (int j = i; j <= n; j += i) {
                s += c[j];
                d[i] -= d[j];
            }
            d[i] += s * (s - 1) / 2;
        }
        partial_sum(d.begin(), d.end(), d.begin());
        vector<int> ans;
        for (auto x : b)
            ans.push_back(upper_bound(d.begin(), d.end(), x) - d.begin());

        return ans;
    }
};