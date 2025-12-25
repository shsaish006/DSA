class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> q;
        for (int i = 0; i < happiness.size(); i++) q.push(happiness[i]);
        long long ans = 0;
        int cnt = 0;
        while (k-- && !q.empty()) {
            int val = q.top();
            q.pop();
            val -= cnt;
            if (val > 0) ans += val;
            cnt++;
        }
        return ans;
    }

};