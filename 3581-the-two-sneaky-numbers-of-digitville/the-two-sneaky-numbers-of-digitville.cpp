class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int>freq;
        vector<int>ans;
        for(int x:nums){
            freq[x]++;
            if(freq[x]==2)
                ans.push_back(x);
        }
        return ans;
        
    }
};