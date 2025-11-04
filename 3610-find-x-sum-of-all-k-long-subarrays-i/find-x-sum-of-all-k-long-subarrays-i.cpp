class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        using pii = pair<int,int>;
        multiset<pii> l, r;
        unordered_map<int,int> cnt;
        long long s = 0;
        vector<int> ans;
        int n = nums.size();

        auto add = [&](int v) {
            if (cnt[v] == 0) return;
            pii p = {cnt[v], v};
            if (!l.empty() && p > *l.begin()) {
                s += 1LL * p.first * p.second;
                l.insert(p);
            } else {
                r.insert(p);
            }
        };

        auto remove = [&](int v) {
            if (cnt[v] == 0) return;
            pii p = {cnt[v], v};
            auto it = l.find(p);
            if (it != l.end()) {
                s -= 1LL * p.first * p.second;
                l.erase(it);
            } else {
                r.erase(r.find(p));
            }
        };

        for (int i = 0; i < n; i++) {
            remove(nums[i]);
            cnt[nums[i]]++;
            add(nums[i]);
            int j = i - k + 1;
            if (j < 0) continue;

            while (!r.empty() && (int)l.size() < x) {
                auto it = prev(r.end());
                pii p = *it;
                s += 1LL * p.first * p.second;
                l.insert(p);
                r.erase(it);
            }
            while ((int)l.size() > x) {
                auto it = l.begin();
                pii p = *it;
                s -= 1LL * p.first * p.second;
                l.erase(it);
                r.insert(p);
            }
            ans.push_back((int)s);

            remove(nums[j]);
            cnt[nums[j]]--;
            add(nums[j]);
        }
        return ans;
    }
};

