class Solution {
public:
    int maxOperations(string s) {
        int n=s.size(), cnt=0, ans=0;
        for(int i=1;i<n;i++){
            if (s[i-1]=='1') cnt++;
            if (s[i-1]== '1' && s[i]== '0') ans+= cnt;
        }
        return ans;
        
    }
};