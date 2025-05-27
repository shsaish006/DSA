class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        int cnt=0;
        for(auto i:s){
            if(i=='1') cnt++;
        }
        int i=0;
        int ans=cnt;
        vector<int>right(n,0),left(n,0);
        int c=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                right[i]=c;
                c=0;
            }
            else c++;
        }
        c=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                left[i]=c;
                c=0;
            }
            else c++;
        }
        while(i<n){
            if(s[i]=='0'){
                int j=i+1;
                while(j<n&&s[j]=='1'){
                    j++;
                }
                if(j!=n&&j!=i+1){
                    ans=max(ans,cnt+right[j-1]+left[i+1]);
                    i=j;
                }else 
                    i++;
            }
            else i++;
        }
        return ans;
        
    }
};