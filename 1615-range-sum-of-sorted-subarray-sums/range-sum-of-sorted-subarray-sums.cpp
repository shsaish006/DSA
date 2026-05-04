class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> a;
        for(int i=0;i<n;i++){
            int s=0;
            for(int j=i;j<n;j++){
                s+=nums[j];
                a.push_back(s);
            }
        }
        sort(a.begin(),a.end());
        long long d=0;
        for(int i=left-1;i<right;i++)
        d=(d+a[i])%(int)(1e9+7);
        return d;
        }
};