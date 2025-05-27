class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            int a=i+1;
            int b='z'-s[i]+1;
            ans+=a*b;
        }
        return ans;
        
    }
};