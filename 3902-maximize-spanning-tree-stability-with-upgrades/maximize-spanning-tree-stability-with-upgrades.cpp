class Solution {
public:
struct dsu {
        vector<int> nums, vals;
        int cnt;
        dsu(int a){
            nums.resize(a);
            vals.assign(a,1);
            cnt=a;
            for(int i=0;i<a;i++) nums[i]=i;
        }
        int f(int a){
            return nums[a]==a?a:nums[a]=f(nums[a]);
        }
        bool u(int a,int b){
            a=f(a); b=f(b);
            if(a==b) return 0;
            if(vals[a]<vals[b]) swap(a,b);
            nums[b]=a;
            vals[a]+=vals[b];
            cnt--;
            return 1;
        }
    };

    int maxStability(int a, vector<vector<int>>& nums, int b) {

        int mn = 1e9;

        dsu d0(a);

        for(auto &v:nums){
            if(v[3]){
                mn=min(mn,v[2]);
                if(!d0.u(v[0],v[1])) return -1;
            }
        }

        for(auto &v:nums) d0.u(v[0],v[1]);
        if(d0.cnt>1) return -1;


        auto ok=[&](int val){

            vector<vector<int>> temp = nums;

            sort(temp.begin(), temp.end(),
            [&](auto &x, auto &y){
                return x[2] > y[2];
            });

            dsu d(a);

            int cnt = b;

            for(auto &v:temp){

                int s=v[2];
                int u=v[0];
                int w=v[1];

                if(s>=val){
                    d.u(u,w);
                }
                else if(cnt && s*2>=val){
                    if(d.u(u,w)) cnt--;
                }
            }

            return d.cnt==1;
        };


        int l=1,r=mn;

        while(l<r){
            int m=(l+r+1)/2;
            if(ok(m)) l=m;
            else r=m-1;
        }

        return l;
    }
};