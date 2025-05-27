class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        if(target>=letters[n-1]){
            return letters[0];
        }
        int s=0;
        int e=letters.size()-1;
        while(s<=e){
            int middle=s+(e-s)/2;
            if(target>=letters[middle]){
                s=middle+1;

            }else{
                e=middle-1;
            }
        }
        return letters[s];
        
    }
};