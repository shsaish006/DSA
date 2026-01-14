// class Solution {
// public:
//     double separateSquares(vector<vector<int>>& squares) {
//         vector<array<int,4>> events;
//         set<int> xs;
//         for(auto &v : squares){
//             int x1=v[0], y1=v[1], l=v[2];
//             int x2=x1+l, y2=y1+l;
//             xs.insert(x1); xs.insert(x2);
//             events.push_back({y1, x1, x2, 1});
//             events.push_back({y2, x1, x2, -1});
//         }

//         vector<int> xs_v(xs.begin(), xs.end());
//         sort(events.begin(), events.end());
//         unordered_map<int,int> idx;
//         for(int i=0;i<xs_v.size();i++) idx[xs_v[i]]=i;

//         vector<int> cnt(xs_v.size()-1, 0);
//         vector<int> seg_len(xs_v.size()-1);
//         int total_len = 0;

//         auto add = [&](int l,int r,int v){
//             for(int i=l;i<r;i++){
//                 if(cnt[i]==0 && v>0) total_len += xs_v[i+1]-xs_v[i];
//                 if(cnt[i]==1 && v<0) total_len -= xs_v[i+1]-xs_v[i];
//                 cnt[i] += v;
//             }
//         };

//         double area=0.0;
//         int y0=0;
//         for(auto &e: events){
//             int y=e[0];
//             area += (double)(y-y0)*total_len;
//             add(idx[e[1]], idx[e[2]], e[3]);
//             y0=y;
//         }

//         double target = area/2.0;
//         fill(cnt.begin(), cnt.end(), 0);
//         total_len=0;
//         double curr_area=0.0;
//         y0=0;
//         for(auto &e: events){
//             int y=e[0];
//             double t = (double)(y-y0)*total_len;
//             if(curr_area + t >= target)
//                 return y0 + (target-curr_area)/total_len;
//             curr_area += t;
//             add(idx[e[1]], idx[e[2]], e[3]);
//             y0=y;
//         }

//         return 0.0;
//     }
// };
struct Node { int l=0,r=0,cnt=0,length=0; };

class magic {
    vector<Node> tr;
    vector<int> nums;
    void build(int u,int l,int r){
        tr[u].l=l,tr[u].r=r;
        if(l!=r){
            int mid=(l+r)>>1;
            build(u<<1,l,mid);
            build(u<<1|1,mid+1,r);
        }
    }
    void pushup(int u){
        if(tr[u].cnt>0) tr[u].length=nums[tr[u].r+1]-nums[tr[u].l];
        else if(tr[u].l==tr[u].r) tr[u].length=0;
        else tr[u].length=tr[u<<1].length+tr[u<<1|1].length;
    }
public:
    magic(const vector<int>& s):nums(s){
        int n=(int)s.size()-1;
        tr.assign(n*4,Node());
        build(1,0,n-1);
    }
    void upd(int u,int l,int r,int k){
        if(tr[u].l>=l && tr[u].r<=r) tr[u].cnt+=k;
        else{
            int mid=(tr[u].l+tr[u].r)>>1;
            if(l<=mid) upd(u<<1,l,r,k);
            if(r>mid) upd(u<<1|1,l,r,k);
        }
        pushup(u);
    }
    int query(){ return tr[1].length; }
};

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<array<int,4>> segs;
        set<int> xs;
        for(auto &v:squares){
            int x1=v[0], y1=v[1], l=v[2];
            int x2=x1+l, y2=y1+l;
            xs.insert(x1); xs.insert(x2);
            segs.push_back({y1,x1,x2,1});
            segs.push_back({y2,x1,x2,-1});
        }

        sort(segs.begin(),segs.end());
        vector<int> st(xs.begin(), xs.end());
        magic tree(st);
        unordered_map<int,int> d;
        for(int i=0;i<(int)st.size();i++) d[st[i]]=i;

        double area=0.0; int y0=0;
        for(auto &s:segs){
            int y=s[0],x1=s[1],x2=s[2],k=s[3];
            area += (double)(y-y0)*tree.query();
            tree.upd(1,d[x1],d[x2]-1,k);
            y0=y;
        }

        double target = area/2.0;
        area=0.0; y0=0;
        tree = magic(st); // reset tree
        for(auto &s:segs){
            int y=s[0],x1=s[1],x2=s[2],k=s[3];
            double t = (double)(y-y0)*tree.query();
            if(area + t >= target)
                return y0 + (target-area)/tree.query();
            area += t;
            tree.upd(1,d[x1],d[x2]-1,k);
            y0=y;
        }

        return 0.0;
    }
};
