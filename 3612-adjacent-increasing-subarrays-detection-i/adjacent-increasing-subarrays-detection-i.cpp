class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& a, int k) {
        int n=a.size(),pre=0,cur=0,mx=0;
        for(int i=0;i<n;i++){
            cur++;
            if(i==n-1||a[i]>=a[i+1]){
                mx=max({mx,cur/2,min(pre,cur)});
                pre=cur;
                cur=0;
            }
        }
        return mx>=k;
    }
};