class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](auto& a, auto& b){
            return a[1] < b[1];
        });
        int n = events.size();
        vector<int> vals(n);
        for (int i = 0; i < n; i++) {
            vals[i] = events[i][2];
            if (i) vals[i] = max(vals[i], vals[i - 1]);
        }
        int val = 0;
        for (int i = 0; i < n; i++) {
            int j = lower_bound(events.begin(), events.begin() + i, events[i][0],
                [](const vector<int>& a, int b){
                    return a[1] < b;
                }) - events.begin() - 1;
            int curr = events[i][2];
            if (j >= 0) curr += vals[j];
            val = max(val, curr);
        }
        return val;
    }


};

