class Solution {
public:
    bool canConstruct(string s, int k) {
        int x=0;
        if(k>s.size()) return false;
        sort(s.begin(),s.end());
        for(int i=0;i<s.size();){
            char a=s[i];
            int n=0;
            while(a==s[i]){
                i++;
                n++;
            }
            if(n%2==1)  x++;
            if(x>k) return false;
        }
        return true;
        
    }
};