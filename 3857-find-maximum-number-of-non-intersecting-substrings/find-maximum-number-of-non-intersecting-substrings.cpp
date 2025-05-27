// class Solution {
// public:
//     int maxSubstrings(string word) {
//         int n = word.size();
//         vector<vector<int>> substrings;

//         unordered_map<char, vector<int>> indices;
//         for (int i = 0; i < n; ++i) {
//             indices[word[i]].push_back(i);
//         }

//         for (auto& [ch, vec] : indices) {
//             int m = vec.size();
//             for (int i = 0; i < m; ++i) {
//                 for (int j = m - 1; j > i; --j) {
//                     if (vec[j] - vec[i] + 1 >= 4) {
//                         substrings.push_back({vec[i], vec[j]});
//                         break;
//                     }
//                 }
//             }
//         }

//         sort(substrings.begin(), substrings.end(), [](auto& a, auto& b) {
//             return a[1] < b[1];
//         });

//         int count = 0, last_end = -1;
//         for (auto& sub : substrings) {
//             if (sub[0] > last_end) {
//                 ++count;
//                 last_end = sub[1];
//             }
//         }

//         return count;
//     }
// };
class Solution {
public:
    int maxSubstrings(string w) {
        int len = w.length();
        if (len < 4) {
            return 0;
        }

        vector<int> dp(len + 1, 0);
        vector<int> max_dp(26, -1);

        for (int i = 1; i <= len; ++i) {
            dp[i] = dp[i-1];

            if (i >= 4) {
                char s = w[i-4];
                int si = s - 'a';
                if (max_dp[si] == -1) {
                    max_dp[si] = dp[i-4];
                } else {
                    max_dp[si] = max(max_dp[si], dp[i-4]);
                }
            }

            char e = w[i-1];
            int ei = e - 'a';
            if (max_dp[ei] != -1) {
                dp[i] = max(dp[i], 1 + max_dp[ei]);
            }
        }
        return dp[len];
    }
};
