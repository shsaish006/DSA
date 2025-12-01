class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end());
        long long s = 0;
        int m = batteries.size();
        
        for (int i = 0; i < m - n; i++) {
            s += batteries[i];
        }
        
        vector<long long> a;
        for (int i = m - n; i < m; i++) {
            a.push_back(batteries[i]);
        }
        
        for (int i = 0; i < n - 1; i++) {
            long long need = (a[i+1] - a[i]) * 1LL * (i + 1);
            if (s >= need) {
                s -= need;
            } else {
                return a[i] + s / (i + 1);
            }
        }
        
        return a[n-1] + s / n;
    }
};