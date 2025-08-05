class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> used(n, false);
        int unplacedCount = n;

        for (int fruitSize : fruits) {
            for (int i = 0; i < n; ++i) {
                if (!used[i] && baskets[i] >= fruitSize) {
                    used[i] = true;
                    --unplacedCount;
                    break;
                }
            }
        }

        return unplacedCount;
    }
};
