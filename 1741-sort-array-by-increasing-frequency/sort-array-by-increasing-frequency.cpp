class Solution {
public:
    typedef pair<int,int >pi;
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int ele:nums){
            mp[ele]++;
        }
        priority_queue<pi,vector<pi>,greater<pi> > pq;
        for (auto x: mp){
            pq.push({x.second,-x.first});
        }
        vector<int> ans;
        while(!pq.empty()){
            int freq=pq.top().first;
            int ele= -pq.top().second;
            for(int i=0;i<freq;i++){
                ans.push_back(ele);
            }
            pq.pop();
        }
        return ans;
        
    }
};