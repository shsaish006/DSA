// class Solution {
// public:
//     int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
//         int n = endTime.size();
//         vector<int> freeTimes;

//         freeTimes.push_back(startTime[0]);
//         for (int i = 1; i < n; ++i) {
//             freeTimes.push_back(startTime[i] - endTime[i - 1]);
//         }
//         freeTimes.push_back(eventTime - endTime[n - 1]);

//         int maxSum = 0, windowSum = 0;
//         for (int i = 0; i < freeTimes.size(); ++i) {
//             windowSum += freeTimes[i];
//             if (i >= k) {
//                 windowSum -= freeTimes[i - k];
//             }
//             if (i >= k - 1) {
//                 maxSum = max(maxSum, windowSum);
//             }
//         }

//         return maxSum;
//     }
// };
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = endTime.size();
        vector<int> nums(n + 1);
        nums[0] = startTime[0];
        for (int i = 1; i < n; ++i) {
            nums[i] = startTime[i] - endTime[i - 1];
        }
        nums[n] = eventTime - endTime[n - 1];

        int ans = 0, s = 0;
        for (int i = 0; i <= n; ++i) {
            s += nums[i];
            if (i >= k) {
                ans = max(ans, s);
                s -= nums[i - k];
            }
        }
        return ans;
    }
};


