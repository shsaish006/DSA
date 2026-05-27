class Solution {
public:
    int numberOfSpecialChars(string w) {
        vector<int>a(26,-1),b(26,1e9);
        
        for(int i=0;i<w.size();i++){
            if(islower(w[i])) a[w[i]-'a']=i;
            else b[w[i]-'A']=min(b[w[i]-'A'],i);
        }
        int cnt=0;
        for(int i=0;i<26;i++){
            cnt+=a[i]!=-1 && b[i]!=1e9 && a[i]<b[i];
        }
        
        return cnt;
    }
};