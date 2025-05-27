class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>map;
        for(char &ch:s){
            map[ch]++;

        }
        int count=0;
        for(auto &freq:map){
            if(freq.second%2!=0){
                count+=1;
            }else{
                count+=2;
            }
        }
        return count;

        
    }
};