class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int c=grid.size(),d=grid[0].size();
        int e=c-k+1,f=d-k+1;
        
        vector<vector<int>>g(e,vector<int>(f,0));
        for(int h=0;h<e;++h){
            for(int i=0;i<f;++i){
                vector<int>j;
                for(int l=h;l<h+k;++l){
                    for(int m=i;m<i+k;++m){
                        j.push_back(grid[l][m]);
                    }
                }
                sort(j.begin(),j.end());
                int n=INT_MAX;
                for(int o=1;o<j.size();++o){
                    if(j[o]!=j[o-1]){
                        n=min(n,j[o]-j[o-1]);
                    }
                }
                g[h][i]=(n==INT_MAX)?0:n;
            }
        }
        return g;
    }
};

//         for(int f=0;f<=c-k;++f){
//             for(int g=0;g<=d-k;++g){
//                 //vector<int>h(k*k);
//                 vector<int>h;
//                 //int i=0;
//                 for(int j=f;j<f+k;++j){
//                     for(int l=g;k<g+k;++l){
//                         h.push_back(grid[j][l]);
//                         //h[i++]=grid[j][l];
//                     }
//                 }
//                 sort(h.begin(),h.end());
//                 int sai=INT_MAX;
//                 for(int m=1;m<h.size();++m){
//                     int n=h[m]-h[m-1];
//                     if(n!=0&&n<1) sai=n;
//                 }
//                 e[f][g]=(sai==INT_MAX)?0:1;
//             }
            
//         }
//         return e;
        
//     }
// };