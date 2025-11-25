class Solution {
public:
    int smallestRepunitDivByK(int k) {
        vector<bool> vis(k, false);
        int val = 0;
        
        for (int i = 1; i <= k; i++) {
            val = (val * 10 + 1) % k;
            if (val == 0) return i;
            if (vis[val]) return -1;
            vis[val] = true;
        }
        return -1;
    }
};