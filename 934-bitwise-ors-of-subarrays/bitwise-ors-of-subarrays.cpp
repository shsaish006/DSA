class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result, current;
        for (int num : arr) {
            unordered_set<int> next;
            next.insert(num);
            for (int val : current) {
                next.insert(num | val);
            }
            result.insert(next.begin(), next.end());
            current = move(next);
        }
        return result.size();
    }
    
};
