class Solution{
public:
    int maximalRectangle(vector<vector<char>>& m){
        if(m.empty()) return 0;
        int r=m.size(),c=m[0].size(),ans=0;
        vector<int> h(c+1);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++) h[j]=m[i][j]=='1'?h[j]+1:0;
            stack<int> st;
            for(int j=0;j<=c;j++){
                int x=j==c?0:h[j];
                while(!st.empty() && h[st.top()]>=x){
                    int ht=h[st.top()];
                    st.pop();
                    int l=st.empty()?0:st.top()+1;
                    ans=max(ans,ht*(j-l));
                }
                st.push(j);
            }
        }
        return ans;}};