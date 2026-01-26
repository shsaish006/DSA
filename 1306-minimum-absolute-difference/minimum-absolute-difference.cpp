class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int n = arr.size();
        int mi = INT_MAX;
        for (int i = 1; i < n; ++i) {
            int d = arr[i] - arr[i - 1];
            if (d < mi) {
                mi = d;
                ans.clear();
                ans.push_back({arr[i - 1], arr[i]});
            } 
            else if (d == mi) {
                ans.push_back({arr[i - 1], arr[i]});
            }
        }
        return ans;
    }
};