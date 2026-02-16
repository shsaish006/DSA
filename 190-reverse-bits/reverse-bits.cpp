class Solution {
public:
    int reverseBits(int n) {
    int ans=0;
    for(int i=0;i<32;i++){
    ans+=(1<<(31-i))*(((n>>i))&1);
    }
    return ans;
    
    
        
    }
};