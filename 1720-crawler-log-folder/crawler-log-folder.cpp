class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt=0;
        for(string i:logs){
            if(i=="../") 
            cnt--;
            else if(i=="./")
            continue;
            else cnt++;
            if(cnt<0)
            cnt=0;
        }
        return cnt;

        
    }
};