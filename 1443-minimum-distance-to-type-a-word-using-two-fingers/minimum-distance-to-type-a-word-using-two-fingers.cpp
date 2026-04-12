class Solution {
public:
    int minimumDistance(string word) {
        vector<int> dp(26, 0), nxt(26, 1e9);

        for (int i = 1; i < word.size(); i++) {
            int a = word[i - 1] - 'A';
            int b = word[i] - 'A';

            fill(nxt.begin(), nxt.end(), 1e9);

            for (int j = 0; j < 26; j++) {
                nxt[j] = min(nxt[j], dp[j] + dist(a, b));
                nxt[a] = min(nxt[a], dp[j] + dist(j, b));
            }

            dp = nxt;
        }

        int ans = 1e9;
        for (int i = 0; i < 26; i++) ans = min(ans, dp[i]);
        return ans;
    }

    int dist(int a, int b) {
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }
};