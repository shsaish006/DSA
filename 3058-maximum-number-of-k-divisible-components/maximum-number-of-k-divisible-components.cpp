class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        int cnt = 0;
        vector<vector<int>> vals(n);
        for(auto &a : edges){
            vals[a[0]].push_back(a[1]);
            vals[a[1]].push_back(a[0]);
        }

        vector<int> mp(n, -1);
        vector<long long> s(n, 0);
        stack<int> st;
        st.push(0);
        mp[0] = -2;

        vector<int> o;

        while(!st.empty()){
            int a = st.top();
            st.pop();
            o.push_back(a);
            for(int b : vals[a]){
                if(mp[b] == -1){
                    mp[b] = a;
                    st.push(b);
                }
            }
        }

        for(int i = n-1; i >= 0; i--){
            int a = o[i];
            s[a] += values[a];
            if(s[a] % k == 0) cnt++;
            if(mp[a] >= 0) s[mp[a]] += s[a];
        }

        return cnt;
    }
};