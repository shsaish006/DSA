class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int ele:stones){
            pq.push(ele);
        }
        while(pq.size()>1){
            int stone1=pq.top();
            pq.pop();
            int stone2=pq.top();
            pq.pop();
            int smash=stone1-stone2;
            if(smash>0) pq.push(smash);
        }
        if(pq.size()>0) return pq.top();
        return 0;

        
    }
};