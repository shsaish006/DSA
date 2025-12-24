class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        priority_queue<int> pq;
        for (int c : capacity) pq.push(c);
        long long totalApples = accumulate(apple.begin(), apple.end(), 0LL);
        int boxesUsed = 0;
        while (totalApples > 0 && !pq.empty()) {
            totalApples -= pq.top();
            pq.pop();
            boxesUsed++;
        }
        return boxesUsed;
    }
};