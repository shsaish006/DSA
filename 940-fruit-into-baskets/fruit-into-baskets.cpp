class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> cnt;
        int ans = 0;
        int j = 0;
        for (int i = 0; i < fruits.size(); ++i) {
            ++cnt[fruits[i]];
            while (cnt.size() > 2) {
                if (--cnt[fruits[j]] == 0) {
                    cnt.erase(fruits[j]);
                }
                ++j;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
        
    }
};
