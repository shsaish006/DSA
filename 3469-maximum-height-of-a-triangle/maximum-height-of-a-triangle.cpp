class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        return max(calc(red,blue),calc(blue,red));
    }
    int calc(int first,int second){
        int k=1;
        int res=0;
        while(true){
            if(k%2==1){
                if(first-k>=0) first-=k,k++;
                else break;
            } else{
                if(second-k>=0) second-=k,k++;
                else break;
            }
            res++;
        }
        return res;
    }
};