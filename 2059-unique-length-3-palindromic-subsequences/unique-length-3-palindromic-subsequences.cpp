class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;

        for(char c = 'a'; c <= 'z'; c++) {
            int l = s.find(c);
            int r = s.rfind(c);

            if(l == -1 || l == r) continue;



            int mask = 0;
            for(int i = l + 1; i < r; i++) {
                int k = s[i] - 'a';
                if(!(mask & (1 << k))) {
                    mask |= (1 << k);
                    ans++;
                }
            }
        }
        return ans;
    }


};
