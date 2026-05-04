class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<array<int,2>> a;
        int b=nums.size();
        for(int i=0;i<b;i++)
            for(int j:nums[i])
                a.push_back({j,i});
                sort(a.begin(), a.end());
                vector<int> cnt(b), d={-100000,100000};
                int s=0, o=0;
                for(int i=0;i<a.size();i++){
                    if(!cnt[a[i][1]]++) o++;
                    while(o==b){
                        if(a[i][0]-a[s][0]<d[1]-d[0])
                        d={a[s][0], a[i][0]};
                        if(!--cnt[a[s][1]]) o--;
                        s++;
                    }
                }
                return d;
        
       

        
    }
};