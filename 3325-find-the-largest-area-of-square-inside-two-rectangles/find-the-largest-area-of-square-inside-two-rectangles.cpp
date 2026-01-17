class Solution {
public:
    struct R { int x1, y1, x2, y2; };

    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        vector<R> a(n);
        for(int i = 0; i < n; i++){
            a[i].x1 = bottomLeft[i][0];
            a[i].y1 = bottomLeft[i][1];
            a[i].x2 = topRight[i][0];
            a[i].y2 = topRight[i][1];
        }

        long long ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int lx = a[i].x1 > a[j].x1 ? a[i].x1 : a[j].x1;
                int rx = a[i].x2 < a[j].x2 ? a[i].x2 : a[j].x2;
                int ly = a[i].y1 > a[j].y1 ? a[i].y1 : a[j].y1;
                int ry = a[i].y2 < a[j].y2 ? a[i].y2 : a[j].y2;
                int w = rx - lx;
                int h = ry - ly;
                if(w > 0 && h > 0){
                    int s = w < h ? w : h;
                    long long v = 1LL * s * s;
                    if(v > ans) ans = v;
                }
            }
        }
        return ans;
    }};



    