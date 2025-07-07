class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        set<int> availableDays;
        int maxDay = 0;
        for (const auto& e : events)
            maxDay = max(maxDay, e[1]);
        
        for (int d = 1; d <= maxDay; ++d)
            availableDays.insert(d);

        int ans = 0;
        for (const auto& e : events) {
            int start = e[0], end = e[1];
            auto it = availableDays.lower_bound(start);
            if (it != availableDays.end() && *it <= end) {
                availableDays.erase(it);
                ++ans;
            }
        }

        return ans;
    }
};
