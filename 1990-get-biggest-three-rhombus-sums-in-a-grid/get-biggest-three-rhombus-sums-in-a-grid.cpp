class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& nums) {
        int a=nums.size(),b=nums[0].size();
        set<int> s;
        
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                
                s.insert(nums[i][j]);
                if(s.size()>3) s.erase(s.begin());
                
                for(int k=1;;k++){
                    
                    if(i-k<0||i+k>=a||j-k<0||j+k>=b) break;
                    
                    int curr=0;
                    
                    for(int d=0;d<k;d++) curr+=nums[i-k+d][j+d];
                    for(int d=0;d<k;d++) curr+=nums[i+d][j+k-d];
                    for(int d=0;d<k;d++) curr+=nums[i+k-d][j-d];
                    for(int d=0;d<k;d++) curr+=nums[i-d][j-k+d];
                    
                    s.insert(curr);
                    if(s.size()>3) s.erase(s.begin());
                }
            }
        }
        
        vector<int> vals;
        for(auto i=s.rbegin();i!=s.rend();i++) vals.push_back(*i);
        return vals;
    }};