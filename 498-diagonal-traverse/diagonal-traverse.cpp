#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans;

        for (int k = 0; k < m + n - 1; ++k) {
            vector<int> temp;
            int i = (k < n) ? 0 : k - n + 1;
            int j = (k < n) ? k : n - 1;
            while (i < m && j >= 0) {
                temp.push_back(mat[i][j]);
                ++i;
                --j;
            }
            if (k % 2 == 0) {
                reverse(temp.begin(), temp.end());
            }
            ans.insert(ans.end(), temp.begin(), temp.end());
        }
        return ans;
    }
};
