class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& a) {
        vector<bool> res;
        int curr = 0;
        for(int val : a){
            curr = (curr * 2 + val) % 5;
            res.push_back(curr == 0);
        }
        return res;
    }};