class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int x : arr) {
            freq[x]++;
        }

        int result = -1;
        for (auto& [num, count] : freq) {
            if (num == count) {
                result = max(result, num); 
            }
        }

        return result;
    }
};
