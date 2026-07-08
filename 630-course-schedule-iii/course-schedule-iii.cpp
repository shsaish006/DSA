class Solution {
public:
//  a=courses
    int scheduleCourse(vector<vector<int>>& a) {
        sort(a.begin(),a.end(), [](auto &x, auto &y){
            return x[1]<y[1];
        });
        priority_queue<int> pq;
        int s=0;
        for(auto &i:a){
            pq.push(i[0]);
            s+=i[0];
            if(s>i[1]) s-=pq.top(), pq.pop();
        }
        return pq.size();
        
    }
};
//  sort karenge course ko last day ke hissab se
//  always take current cour
//  agar total time exceeds the current course remove the longest dur cour (max heap)
//  heap jo hain always maximum no of course jo completed ho sake