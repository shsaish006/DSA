using ll = long long;
using pii = pair<ll, int>;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> count(n);
        priority_queue<int, vector<int>, greater<>> available;
        priority_queue<pii, vector<pii>, greater<>> occupied;

        for (int i = 0; i < n; ++i) available.push(i);
        sort(meetings.begin(), meetings.end());

        for (auto& m : meetings) {
            ll start = m[0], end = m[1];
            while (!occupied.empty() && occupied.top().first <= start) {
                available.push(occupied.top().second);
                occupied.pop();
            }
            if (!available.empty()) {
                int room = available.top();
                available.pop();
                occupied.push({end, room});
                count[room]++;
            } else {
                auto [freeTime, room] = occupied.top();
                occupied.pop();
                ll newEnd = freeTime + (end - start);
                occupied.push({newEnd, room});
                count[room]++;
            }
        }

        int res = 0;
        for (int i = 1; i < n; ++i) {
            if (count[i] > count[res]) res = i;
        }
        return res;
    }
};
