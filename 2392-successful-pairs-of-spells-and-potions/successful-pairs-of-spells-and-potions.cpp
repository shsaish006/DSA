class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> ans(spells.size());
        for (int i = 0; i < spells.size(); i++) {
            long long need = (success + spells[i] - 1) / spells[i];
            int idx = lower_bound(potions.begin(), potions.end(), need) - potions.begin();
            ans[i] = m - idx;
        }
        return ans;
    }
};
