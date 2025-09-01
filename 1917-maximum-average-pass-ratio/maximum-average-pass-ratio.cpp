class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](int a, int b) {
            return (double)(a + 1) / (b + 1) - (double)a / b;
        };
        priority_queue<pair<double, pair<int,int>>> pq;
        for (auto& e : classes) {
            pq.push({gain(e[0], e[1]), {e[0], e[1]}});
        }
        while (extraStudents--) {
            auto [g, p] = pq.top(); pq.pop();
            int a = p.first + 1, b = p.second + 1;
            pq.push({gain(a, b), {a, b}});
        }
        double ans = 0;
        while (!pq.empty()) {
            auto [g, p] = pq.top(); pq.pop();
            ans += (double)p.first / p.second;
        }
        return ans / classes.size();
    }
};
