class Solution {
public:
    string sortVowels(string s) {
        vector<char> v;
        for (char c : s) if (string("aeiouAEIOU").find(c) != string::npos) v.push_back(c);
        sort(v.begin(), v.end());
        int j = 0;
        for (char &c : s) if (string("aeiouAEIOU").find(c) != string::npos) c = v[j++];
        return s;
    }
};
