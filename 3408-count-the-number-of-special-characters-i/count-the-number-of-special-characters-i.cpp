class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans=0; for(char c='a';c<='z';c++) 
        ans+=word.find(c)!=string::npos&&word.find(c-32)!=string::npos;
        return ans;
    }
};