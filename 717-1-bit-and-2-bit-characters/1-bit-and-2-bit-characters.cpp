class Solution {
public:
    bool isOneBitCharacter(vector<int>& a) {
        int n = a.size(), cnt = 0, idx = n - 2;
        while (idx >= 0 && a[idx] == 1) {
            cnt++;
            idx--;
        }
        return cnt % 2 == 0;
    }
};