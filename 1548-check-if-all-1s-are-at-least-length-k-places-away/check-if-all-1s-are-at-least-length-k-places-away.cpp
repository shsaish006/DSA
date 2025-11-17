class Solution {
public:
    bool kLengthApart(vector<int>& a, int k) {
        int p = -1;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == 1) {
                if (p != -1 && i - p - 1 < k) return false;
                p = i;
            }
        }
        return true;
    }
    
};
