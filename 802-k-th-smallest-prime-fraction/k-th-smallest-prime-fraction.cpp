class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& a, int k) {
        int n=a.size();
         double l=0, r=1;
        while(1){
            double m=(l+r)/2.0;
            int cnt=0, i=0;
            double aa=0;
            int x=0, y=1;
            for(int j=1;j<n;j++){
                while(i<j && a[i]<=m *a[j]) i++;
                cnt+=i;
                if(i>0){
                    double v=(double)a[i-1]/a[j];
                    if(v>aa){
                        aa=v;
                        x=i-1;
                        y=j;
                    }
                }
            }
            if(cnt==k) return {a[x], a[y]};
            if(cnt<k) l=m;
            else r=m;
        }

        
    }
};