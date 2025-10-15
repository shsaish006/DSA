class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& a) {
        int o=0, p=0, c=0, n=a.size();
        for(int i=0;i<n;i++){
            c++;
            if(i==n-1||a[i]>=a[i+1]){
                o=max({o,c/2,min(p,c)});
                p=c;
                c=0;
            }
        }
        return o;
    }
};