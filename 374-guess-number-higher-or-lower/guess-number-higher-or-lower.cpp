/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int a=1, b=n;
        while(a<=b){
            int c=a+(b-a)/2;
            int d=guess(c);
            if(d==0) return c;
            if(d<0) b=c-1;
            else a=c+1;
        }
        return a;
        
    }
};