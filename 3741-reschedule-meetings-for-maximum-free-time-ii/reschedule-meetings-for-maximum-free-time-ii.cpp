#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, const vector<int>& startTime, const vector<int>& endTime) {
        int n = startTime.size();
        int maxTime = 0;

        vector<int> leftGaps(n);
        leftGaps[0] = startTime[0];
        for (int i = 1; i < n; ++i) {
            int gap = startTime[i] - endTime[i - 1];
            leftGaps[i] = max(leftGaps[i - 1], gap);
        }

        vector<int> rightGaps(n);
        rightGaps[n - 1] = eventTime - endTime[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            int gap = startTime[i + 1] - endTime[i];
            rightGaps[i] = max(rightGaps[i + 1], gap);
        }

        for (int i = 0; i < n; ++i) {
            int leftGap = (i == 0) ? leftGaps[i] : startTime[i] - endTime[i - 1];
            int rightGap = (i == n - 1) ? rightGaps[i] : startTime[i + 1] - endTime[i];
            int meetingDuration = endTime[i] - startTime[i];

            int includeMeeting = 0;
            if ((i > 0 && leftGaps[i - 1] >= meetingDuration) ||
                (i < n - 1 && rightGaps[i + 1] >= meetingDuration)) {
                includeMeeting = meetingDuration;
            }

            int total = leftGap + includeMeeting + rightGap;
            maxTime = max(maxTime, total);
        }

        return maxTime;
    }


    
};
