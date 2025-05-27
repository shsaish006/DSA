class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        stack<int>st;
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                if(!st.empty()){
                    count++;
                    st.pop();
                }
            }else{
                st.push('b');
            }
        }
        return count;
        
    }
};