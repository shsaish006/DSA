class Solution {
public:
    int countValidSelections(vector<int>& a) {
        int s = 0;
        for (int val : a) s += val;
        int ans = 0, curr = 0;
        for (int idx = 0; idx < a.size(); idx++) {
            if (a[idx] == 0) {
                int x = curr * 2 - s;
                if (x == 0) ans += 2;
                else if (abs(x) == 1) ans++;
            } else curr += a[idx];
        }

        return ans;


    }
    
};
