class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(boxes[j]=='1'){
                    ans[i]+=abs(j-i);
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=0;j--){
                if(boxes[j]=='1'){
                    ans[i]+=abs(i-j);
                }
            }
        }
        return ans;

        
        
    }
};