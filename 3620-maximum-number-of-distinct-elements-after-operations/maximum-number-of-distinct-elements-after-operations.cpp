class Solution{
public:
    int maxDistinctElements(vector<int>& a,int b){
        sort(a.begin(),a.end());
        int s=0,o=INT_MIN;
        for(int val:a){
            int c=min(val+b,max(val-b,o+1));
            if(c>o){
                s++;
                o=c;
            }
        }
        return s;
    }
};