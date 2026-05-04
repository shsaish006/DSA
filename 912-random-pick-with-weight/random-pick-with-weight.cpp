class Solution {
public:
vector<int> s;
    Solution(vector<int>& w) {
        s.push_back(0);
        for(int x:w) s.push_back(s.back()+x);
        
    }
    
    int pickIndex() {
        
        int x=rand()%s.back();
        int i=upper_bound(s.begin(),s.end(),x)-s.begin();
        return i-1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */