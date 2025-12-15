class Solution {
public:
    long long getDescentPeriods(vector<int>& a) {
        long long ans = 1, cnt = 1;
        int n = a.size();
        for (int i = 1; i < n; i++) {
            if (a[i - 1] - a[i] == 1) cnt++;
            else cnt = 1;
            ans += cnt;
        }
        return ans;



        
    }
};
