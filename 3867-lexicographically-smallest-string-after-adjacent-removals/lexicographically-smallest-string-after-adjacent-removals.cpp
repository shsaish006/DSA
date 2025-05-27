// class Solution {
// public:
//     bool is_consecutive(char c1, char c2) {
//         if (c1 == c2) return false;
//         int diff = abs(c1 - c2);
//         return diff == 1 || diff == 25;
//     }

//     string lexicographicallySmallestString(string s) {
//         queue<string> q;
//         set<string> visited;

//         string min_s = s;

//         q.push(s);
//         visited.insert(s);

//         while (!q.empty()) {
//             string current_s = q.front();
//             q.pop();

//             min_s = min(min_s, current_s);

//             for (int i = 0; i + 1 < current_s.length(); ++i) {
//                 if (is_consecutive(current_s[i], current_s[i+1])) {
//                     string next_s = current_s.substr(0, i) + current_s.substr(i + 2);

//                     if (visited.find(next_s) == visited.end()) {
//                         q.push(next_s);
//                         visited.insert(next_s);
//                     }
//                 }
//             }
//         }
//         return min_s;
//     }
// }



          
class Solution {
public:
    string lexicographicallySmallestString(string s) {
        string gralvenoti = s;

        int n = s.size();
        vector<vector<bool>> can(n, vector<bool>(n, false));

        auto isConsecutive = [&](char a, char b) {
            int d = abs(a - b);
            return d == 1 || d == 25;  
        };                            

        for (int len = 1; len <= n; ++len) {
            for (int l = 0; l + len - 1 < n; ++l) {
                int r = l + len - 1;
                if ((len & 1) == 1) continue;
                for (int m = l + 1; m <= r; ++m) {
                    if (isConsecutive(s[l], s[m])) {
                        bool leftGood  = (m == l + 1) || can[l+1][m-1];
                        bool rightGood = (m == r)   || can[m+1][r];
                        if (leftGood && rightGood) {
                            can[l][r] = true;
                            break;
                        }
                    }
                }
            }
        }

        vector<string> dp(n+1);
        dp[n] = "";
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = s[i] + dp[i+1];
            for (int j = i + 1; j < n; ++j) {
                if (isConsecutive(s[i], s[j]) &&
                    ((j == i + 1) || can[i+1][j-1])) {
                    if (dp[j+1] < dp[i]) {
                        dp[i] = dp[j+1];
                    }
                }
            }
        }

        return dp[0];
    }
};