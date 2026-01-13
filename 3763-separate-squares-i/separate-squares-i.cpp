class Solution {
public:
    double areaBelow(double y, const vector<vector<int>>& a){
        double t=0.0;
        for(auto& v:a){
            double b=v[1];
            double c=v[2];
            if(b+c<=y) t+=c*c;
            else if(b<y) t+=c*(y-b);
        }
        return t;
    }

    double separateSquares(vector<vector<int>>& a) {
        double tot=0;
        double lo=1e18,hi=-1e18;
        for(auto& v:a){
            tot+= (double)v[2]*v[2];
            lo=min(lo,(double)v[1]);
            hi=max(hi,(double)v[1]+v[2]);
        }
        double need=tot/2.0;
        for(int it=0;it<70;it++){
            double mid=(lo+hi)/2.0;
            if(areaBelow(mid,a)>=need) hi=mid;
            else lo=mid;
        }
        return hi;
    }
};
