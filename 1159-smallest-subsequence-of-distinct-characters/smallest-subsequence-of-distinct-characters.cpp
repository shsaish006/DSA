class Solution {
public:
    string smallestSubsequence(string s) {
        int a[26]={},b=0;
        for(int i=0;i<s.size();i++) a[s[i]-'a']=i;
        string c;
        for(int i=0;i<s.size();i++){
            if(b>>s[i]-'a'&1) continue;
            while(c.size()&&c.back()>s[i]&&a[c.back()-'a']>i){
                b^=1<<(c.back()-'a');
                c.pop_back();
            }
            c+=s[i];
            b|=1<<(s[i]-'a');
        }
        return c;
    }
};