class Solution {
public:
    int finalValueAfterOperations(vector<string>& a) {
        int s = 0;
        for (auto &o : a) {
            if (o.find('+') != string::npos) s++;
            else s--;
        }
        return s;
    }
};
