class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        for (int x : nums) {
            while (!st.empty()) {
                int g = gcd(st.back(), x);
                if (g == 1) break;
                x = 1LL * x * st.back() / g;
                st.pop_back();
            }
            st.push_back(x);
        }
        return st;}};
