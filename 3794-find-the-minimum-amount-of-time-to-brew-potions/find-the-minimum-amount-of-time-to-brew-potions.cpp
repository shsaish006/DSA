class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        vector<long long> f(n);
        for (int x : mana) {
            long long cur = 0;
            for (int i = 0; i < n; ++i)
                cur = max(cur, f[i]) + 1LL * skill[i] * x;
            for (int i = n - 1; i >= 0; --i)
                f[i] = cur, cur -= 1LL * skill[i] * x;
        }
        return f.back();
    }
};