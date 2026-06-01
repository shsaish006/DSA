class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int ans = accumulate(cost.begin(), cost.end(), 0);
        for (int i = cost.size() - 3; i >= 0; i -= 3) ans -= cost[i];
        return ans;
    }
};