class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        int n = s.size();
        int f = 0;
        string str = "";

        for (int i = 0; i < n; i++) {
            if (x > y) {
                if (!str.empty() && str.back() == 'a' && s[i] == 'b') {
                    str.pop_back();
                    ans += x;
                } else {
                    str += s[i];
                }
                f = 1;
            } else {
                if (!str.empty() && str.back() == 'b' && s[i] == 'a') {
                    str.pop_back();
                    ans += y;
                } else {
                    str += s[i];
                }
            }
        }

        string st = "";
        for (int i = 0; i < str.size(); i++) {
            if (f == 0) {
                if (!st.empty() && st.back() == 'a' && str[i] == 'b') {
                    st.pop_back();
                    ans += x;
                } else {
                    st += str[i];
                }
            } else {
                if (!st.empty() && st.back() == 'b' && str[i] == 'a') {
                    st.pop_back();
                    ans += y;
                } else {
                    st += str[i];
                }
            }
        }

        return ans;
        
    }
};
