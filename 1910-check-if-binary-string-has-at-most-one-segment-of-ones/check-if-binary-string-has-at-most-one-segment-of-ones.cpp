class Solution {
public:
    bool checkOnesSegment(string s) {
        string t = s;
        sort(t.rbegin(), t.rend());
        return s == t;
    }
};