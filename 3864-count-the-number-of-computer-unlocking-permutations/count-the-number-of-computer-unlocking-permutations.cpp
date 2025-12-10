class Solution {
public:
    int countPermutations(vector<int>& a) {
        const int mod = 1000000007;
        long long ans = 1;
        int n = a.size();
        for(int i = 1; i < n; i++){
            if(a[i] <= a[0]) return 0;
            ans = ans * i % mod;
        }
        
        return ans;
    }
};
