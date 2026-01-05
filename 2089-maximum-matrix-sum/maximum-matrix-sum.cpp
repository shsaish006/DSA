class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long s = 0;
        int mi = INT_MAX;
        bool o = false;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                int val = matrix[i][j];
                if (val < 0) o = !o;
                val = val < 0 ? -val : val;
                if (val < mi) mi = val;
                s += val;
            }
        }
        if (o) s -= 2LL * mi;
        return s;
    }};