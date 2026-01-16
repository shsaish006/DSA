class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        h.push_back(1);
        h.push_back(m);
        v.push_back(1);
        v.push_back(n);
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        unordered_map<int,int> o;
        for(int i=0;i<h.size();i++){
            for(int j=i+1;j<h.size();j++){
                o[h[j]-h[i]]++;
            }
        }
        long long ans=0,c=1000000007;
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                int d=v[j]-v[i];
                if(o.count(d)) ans=max(ans,(long long)d);
            }
        }
        return ans?ans*ans%c:-1;
    }
};