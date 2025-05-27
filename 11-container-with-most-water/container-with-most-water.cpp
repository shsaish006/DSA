//SHIVAM
class Solution {
public:
    int maxArea(vector<int>&H) {
        int i=0,j=H.size()-1;
        int ans=0;
        while(i<j){
            int t=min(H[i],H[j])*(j-i);
            ans=max(ans,t);
            if(H[i]<H[j]){
                ++i;
            }else{
                --j;
            }
        }
        return ans;
        
        
    }
};