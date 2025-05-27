class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>v;
        for(auto i:words){
            for(auto j:words){
                if(i!=j){
                    int num=j.find(i);
                    if(num>=0){
                        v.push_back(i);
                        break;
                    }
                }
            }
        }
        return v;
        
    }
};