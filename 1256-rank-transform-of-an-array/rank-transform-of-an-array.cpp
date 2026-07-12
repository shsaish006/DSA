class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& a) {
        vector<int> b=a;
        sort(b.begin(),b.end());
        b.erase(unique(b.begin(),b.end()),b.end());
        for(int &x:a) x=lower_bound(b.begin(),b.end(),x)-b.begin()+1;
        return a;
    }
};