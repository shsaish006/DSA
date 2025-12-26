class Solution {
public:
    int bestClosingTime(string s) {
        int curr = 0;
        int val = 0;
        int ans = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'Y') curr++;
            else curr--;
            
            if (curr > val) {
                val = curr;
                ans = i + 1;
            }
        }
        return ans;
    }};