class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> nums;
        long long s = 4LL * side;

        for (auto &a : points) {
            long long b = a[0], c = a[1];
            if (b == 0) nums.push_back(c);
            else if (c == side) nums.push_back(side + b);
            else if (b == side) nums.push_back(3LL * side - c);
            else nums.push_back(4LL * side - b);
        }

        sort(nums.begin(), nums.end());
        int a = nums.size();

        vector<long long> vals = nums;
        for (int i = 0; i < a; i++) vals.push_back(nums[i] + s);

        auto ok = [&](long long d) {
            for (int i = 0; i < a; i++) {
                int curr = i;
                for (int j = 1; j < k; j++) {
                    curr = lower_bound(vals.begin() + curr + 1, vals.begin() + i + a, vals[curr] + d) - vals.begin();
                    if (curr >= i + a) break;
                }
                if (curr < i + a && vals[curr] - vals[i] <= s - d) return true;
            }
            return false;
        };

        int b = 0, c = side;
        while (b < c) {
            int d = (b + c + 1) / 2;
            if (ok(d)) b = d;
            else c = d - 1;
        }

        return b;
    }
};