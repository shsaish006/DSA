class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> needTeach;
        for (auto& f : friendships) {
            int u = f[0], v = f[1];
            bool canCommunicate = false;
            for (int langU : languages[u - 1]) {
                if (find(languages[v - 1].begin(), languages[v - 1].end(), langU) != languages[v - 1].end()) {
                    canCommunicate = true;
                    break;
                }
            }
            if (!canCommunicate) {
                needTeach.insert(u);
                needTeach.insert(v);
            }
        }
        if (needTeach.empty()) return 0;
        vector<int> langCount(n + 1, 0);
        for (int person : needTeach) {
            for (int lang : languages[person - 1]) {
                langCount[lang]++;
            }
        }
        int best = 0;
        for (int i = 1; i <= n; i++) {
            best = max(best, langCount[i]);
        }
        return (int)needTeach.size() - best;
    }
};
