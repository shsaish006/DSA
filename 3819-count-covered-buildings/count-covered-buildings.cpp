// class Solution {
// public:
//     int countCoveredBuildings(int n, vector<vector<int>>& vals) {
//         map<int, vector<int>> a, b;
//         for (auto &curr : vals) {
//             a[curr[0]].push_back(curr[1]);
//             b[curr[1]].push_back(curr[0]);
//         }
//         for (auto &curr : a) sort(curr.second.begin(), curr.second.end());
//         for (auto &curr : b) sort(curr.second.begin(), curr.second.end());
//         int cnt = 0;
//         for (auto &curr : vals) {
//             int x = curr[0], y = curr[1];
//             auto &l1 = a[x];
//             auto &l2 = b[y];
//             if (l2.front() < x && x < l2.back() && l1.front() < y && y < l1.back()) cnt++;
//         }
//         return cnt;
//     }
// };
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& vals) {
        map<int, int> xLeft, xRight, yLeft, yRight;
        for (auto &curr : vals) {
            int x = curr[0], y = curr[1];
            if (!xLeft.count(y)) xLeft[y] = x; else xLeft[y] = min(xLeft[y], x);
            if (!xRight.count(y)) xRight[y] = x; else xRight[y] = max(xRight[y], x);
            if (!yLeft.count(x)) yLeft[x] = y; else yLeft[x] = min(yLeft[x], y);
            if (!yRight.count(x)) yRight[x] = y; else yRight[x] = max(yRight[x], y);
        }

        int cnt = 0;
        for (auto &curr : vals) {
            int x = curr[0], y = curr[1];
            bool hasLeft  = x > xLeft[y];
            bool hasRight = x < xRight[y];
            bool hasDown  = y > yLeft[x];
            bool hasUp    = y < yRight[x];
            if (hasLeft && hasRight && hasUp && hasDown) cnt++;
        }
        return cnt;
    }
};