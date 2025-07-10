#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        int res = 0;

        vector<int> left_gaps(n, 0);
        left_gaps[0] = startTime[0];
        for (int meet = 1; meet < n; ++meet) {
            left_gaps[meet] = max(left_gaps[meet - 1], startTime[meet] - endTime[meet - 1]);
        }

        vector<int> right_gaps(n, 0);
        right_gaps[n - 1] = eventTime - endTime[n - 1];
        for (int meet = n - 2; meet >= 0; --meet) {
            right_gaps[meet] = max(right_gaps[meet + 1], startTime[meet + 1] - endTime[meet]);
        }

        for (int meet = 0; meet < n; ++meet) {
            int left_gap = (meet == 0) ? left_gaps[meet] : startTime[meet] - endTime[meet - 1];
            int right_gap = (meet == n - 1) ? right_gaps[meet] : startTime[meet + 1] - endTime[meet];

            int interval = 0;
            if ((meet != 0 && left_gaps[meet - 1] >= (endTime[meet] - startTime[meet])) ||
                (meet != n - 1 && right_gaps[meet + 1] >= (endTime[meet] - startTime[meet]))) {
                interval = endTime[meet] - startTime[meet];
            }

            res = max(res, left_gap + interval + right_gap);
        }

        return res;
    }
};
