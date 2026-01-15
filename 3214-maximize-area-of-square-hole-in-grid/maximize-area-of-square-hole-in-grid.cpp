class Solution{
public:
    int maximizeSquareHoleArea(int n,int m,vector<int>& a,vector<int>& b){
        auto g=[&](vector<int>& nums){
            unordered_set<int> s(nums.begin(),nums.end());
            int o=1;
            for(int val:nums){
                if(!s.count(val-1)){
                    int curr=val,cnt=1;
                    while(s.count(curr+1)){
                        curr++;
                        cnt++;
                    }
                    if(cnt>o) o=cnt;
                }
            }
            return o+1;
        };
        int s=g(a),o=g(b);
        int d=min(s,o);
        return d*d; }};