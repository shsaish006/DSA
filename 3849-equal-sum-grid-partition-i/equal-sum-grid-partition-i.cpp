class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        long long s = 0, curr = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                s += a[i][j];
            }
        }
        if(s & 1) return false;

        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < m; j++){
                curr += a[i][j];
            }
            if(curr == s - curr) return true;
        }

        curr = 0;
        for(int j = 0; j < m - 1; j++){
            for(int i = 0; i < n; i++){
                curr += a[i][j];
            }
            if(curr == s - curr) return true;
        }

        return false;
    }
};