// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int n=nums.size();
//         if(n<2){
//             return n;
//         }
//         sort(nums.begin(),nums.end());
//         int ans=1,t=1;
//         for(int i=1;i<n;i++){
//             if(nums[i]==nums[i-1]){
//                 continue;
//             }
//             if(nums[i]==nums[i-1]+1){
//                 ans=max(ans,++i);
//             }else{
//                 t=1;
//             }
//         }
//         return ans;
        
//     }
// };
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        unordered_map<int, int> d;
        for (int x : nums) {
            int y = x;
            while (s.contains(y)) {
                s.erase(y++);
            }
            d[x] = (d.contains(y) ? d[y] : 0) + y - x;
            ans = max(ans, d[x]);
        }
        return ans;
    }
};