class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int a, b, c, nums=0;
        for(a=left; a<=right; a++){
            b=0;
            c=a;
            while(c){
                b += c & 1;
                c >>= 1;
            }
            if(b==2||b==3||b==5||b==7||b==11||b==13||b==17||b==19) nums++;
        }
        return nums;
    }
};