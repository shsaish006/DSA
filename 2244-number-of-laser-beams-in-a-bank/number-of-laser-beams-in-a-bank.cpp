class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> vals;
        for (auto& s : bank) {
            int c = 0;
            for (auto ch : s) if (ch == '1') c++;
            if (c) vals.push_back(c);
        }
        int a = 0;
        for (int idx1 = 1; idx1 < vals.size(); idx1++) a += vals[idx1] * vals[idx1 - 1];
        return a;
    }
};
