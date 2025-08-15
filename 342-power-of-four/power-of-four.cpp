class Solution {
public:
    bool isPowerOfFour(int n) {
        if(!n)
        return false;
        else if(n==1)
        return true;
        else if(n%4==0)
        return isPowerOfFour(n/4);
        else
        return false;
    

        
    }
};