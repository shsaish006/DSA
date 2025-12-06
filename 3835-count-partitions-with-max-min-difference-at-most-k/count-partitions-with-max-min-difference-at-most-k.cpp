class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        int mod = 1000000007;
        
        vector<int> f(n + 1), g(n + 1);
        f[0] = 1;
        g[0] = 1;

        deque<int> mn, mx;
        int l = 1;

        for(int r = 1; r <= n; r++){
            int x = nums[r - 1];

            while(!mn.empty() && mn.back() > x) mn.pop_back();
            mn.push_back(x);

            while(!mx.empty() && mx.back() < x) mx.pop_back();
            mx.push_back(x);

            while(!mn.empty() && !mx.empty() && mx.front() - mn.front() > k){
                int y = nums[l - 1];
                if(mn.front() == y) mn.pop_front();
                if(mx.front() == y) mx.pop_front();
                l++;
            }
        int sub = (l >= 2 ? g[l - 2] : 0);
            f[r] = (g[r - 1] - sub + mod) % mod;
            g[r] = (g[r - 1] + f[r]) % mod;
        }
        return f[n];
    }
};