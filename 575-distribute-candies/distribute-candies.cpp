class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int,int> mp;
        for(int x: candyType)
        ++mp[x];
        return min(candyType.size()/2,mp.size());
        
    }
};