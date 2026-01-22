class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        vector<int> vals=nums;
        int cnt=0;
        while(true){
            bool ok=true;
            for(int i=1;i<(int)vals.size();i++){
                if(vals[i]<vals[i-1]){
                    ok=false;
                    break;
                }
            }
            if(ok) break;
            int s=vals[0]+vals[1];
            int i=0;
            for(int j=1;j<(int)vals.size()-1;j++){
                int val=vals[j]+vals[j+1];
                if(val<s){
                    s=val;
                    i=j;
                }
            }
            vals[i]=s;
            vals.erase(vals.begin()+i+1);
            cnt++;
        }
        return cnt;
        
    }
  


  
};