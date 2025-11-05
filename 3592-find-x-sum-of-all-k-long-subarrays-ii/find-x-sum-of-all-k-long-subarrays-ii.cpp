class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        using pii = pair<int, int>;
        multiset<pii> top, rest;
        unordered_map<int, int> freq;
        long long sum = 0;
        vector<long long> ans;

        auto moveUp = [&]() {
            while ((int)top.size() < x && !rest.empty()) {
                auto it = prev(rest.end());
                sum += 1LL * it->first * it->second;
                top.insert(*it);
                rest.erase(it);
            }
        };

        auto balance = [&]() {
            while ((int)top.size() > x) {
                auto it = top.begin();
                sum -= 1LL * it->first * it->second;
                rest.insert(*it);
                top.erase(it);
            }
        };

        auto add = [&](int v) {
            int c = freq[v];
            pii p = {c, v};
            if (top.find(p) != top.end()) {
                sum -= 1LL * p.first * p.second;
                top.erase(top.find(p));
            } else if (rest.find(p) != rest.end()) {
                rest.erase(rest.find(p));
            }

            ++freq[v];
            p.first++;

            if (!top.empty() && p > *top.begin()) {
                top.insert(p);
                sum += 1LL * p.first * p.second;
            } else {
                rest.insert(p);
            }

            moveUp();
            balance();
        };

        auto remove = [&](int v) {
            int c = freq[v];
            if (c == 0) return;

            pii p = {c, v};
            if (top.find(p) != top.end()) {
                sum -= 1LL * p.first * p.second;
                top.erase(top.find(p));
            } else if (rest.find(p) != rest.end()) {
                rest.erase(rest.find(p));
            }

            --freq[v];
            if (freq[v] > 0) {
                p.first--;
                if (!top.empty() && p > *top.begin()) {
                    top.insert(p);
                    sum += 1LL * p.first * p.second;
                } else {
                    rest.insert(p);
                }
            }

            moveUp();
            balance();
        };

        for (int i = 0; i < nums.size(); ++i) {
            add(nums[i]);
            if (i >= k - 1) {
                ans.push_back(sum);
                remove(nums[i - k + 1]);
            }
        }

        return ans;
    }
};
