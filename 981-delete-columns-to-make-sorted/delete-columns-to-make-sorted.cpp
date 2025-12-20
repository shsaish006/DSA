class Solution {
public:
    int minDeletionSize(vector<string>& s) {
        int n = s.size();
        int m = s[0].size();
        int cnt = 0;
        for(int j = 0; j < m; j++) {
            for(int i = 1; i < n; i++) {
                if(s[i][j] < s[i - 1][j]) {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
    
};
