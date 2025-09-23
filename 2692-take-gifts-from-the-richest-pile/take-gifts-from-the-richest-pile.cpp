class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long> h;
        for(int v: gifts) h.push(v);
        while(k--){
            long long x=h.top();
            h.pop();
            h.push((long long) sqrt(x));
        }
        long long ans=0;
        while(!h.empty()){
            ans+=h.top();
            h.pop();
        }
        return ans;
        
    }
};