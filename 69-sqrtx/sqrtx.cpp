class Solution {
public:
    int mySqrt(int x) {
        int start=1;
        int end=x;
        if(x<2){
            return x;
        }
        int ans;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(mid==x/mid){
                return mid;

            }
            else if(mid>x/mid){
                end=mid-1;

            }else{
                ans=mid;
                start=mid+1;
            }
        }
        return ans;
    }
};
        