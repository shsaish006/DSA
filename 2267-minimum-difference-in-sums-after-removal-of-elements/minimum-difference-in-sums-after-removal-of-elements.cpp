class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int m = nums.size(), n = m / 3;
        priority_queue<int> maxq;
        priority_queue<int, vector<int>, greater<int>> minq;
        vector<long long> left(m, 0), right(m, 0);
        long long sum = 0;
        for (int i = 0; i < m; ++i) {
            sum += nums[i];
            maxq.push(nums[i]);
            if (maxq.size() > n) {
                sum -= maxq.top();
                maxq.pop();
            }
            if (i >= n - 1) left[i] = sum;
        }
        sum = 0;
        for (int i = m - 1; i >= 0; --i) {
            sum += nums[i];
            minq.push(nums[i]);
            if (minq.size() > n) {
                sum -= minq.top();
                minq.pop();
            }
            if (i <= m - n) right[i] = sum;
        }
        long long res = LLONG_MAX;
        for (int i = n - 1; i < m - n; ++i) {
            res = min(res, left[i] - right[i + 1]);
        }
        return res;
    }
};
