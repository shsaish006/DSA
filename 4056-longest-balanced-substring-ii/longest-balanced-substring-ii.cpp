class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        vector<array<int,3>>p(1,{0,0,0});
        for(char c:s){
            array<int,3>last=p.back();
            last[c-'a']++;
            p.push_back(last);
        }
        int ans=0;
        unordered_map<long long,int> first;
        for(int i=0;i<p.size();i++){
            int a=p[i][0], b=p[i][1], c=p[i][2];

           

       
        long long keys[7];
        keys[0]=encode(0,a-b,a-c);
        keys[1]=encode(1,a-b,c);
        keys[2]=encode(2,b-c,a);
        keys[3]=encode(3,c-a,b);
        keys[4]=encode(4,b,c);
        keys[5]=encode(5,c,a);
        keys[6]=encode(6,a,b);
        for(int k=0;k<7;k++){
            if(first.count(keys[k])) 
                ans=max(ans,i-first[keys[k]]);
            else
                first[keys[k]]=i;
        }
        }
          return ans;

        
    }
    private:
    long long encode(int t,int x, int y){
        long long offset=100000;
        return ((long long)t << 40) 
               | ((long long)(x + offset) << 20) 
               | (long long)(y + offset);
    }
};


        