// class Solution {
// public:
//     int minimumPairRemoval(vector<int>& nums) {
//         int s=nums.size();
//         vector<long long> vals(nums.begin(),nums.end());
//         vector<int> left(s),right(s);
//         for(int a=0;a<s;a++){
//             left [a]=a-1;
//             right[a]=(a+1<s?a+1:-1);
//         }
//         multiset<pair<long long,int>>o;
//         int cnt=0;
//         for(int a=0;a+1<s;a++){
//             if(vals[a]>vals[a+1]){
//                 cnt++;
//             o.insert({
//                 vals[a]+vals[a+1],a
//             });
//             }
//         }
//         int upd=0;
//         while(cnt>0){
//             auto it=o.begin();
//             long long val=it->first;
//             int a=it->second;
//             o.erase(it);
//             int b=right[a];
//             if(b==-1) continue; 
//             if(vals[a]<=vals[b]) continue;
//             upd++;
//             if(left[a]!=-1 && vals[left[a]]>vals[a]) cnt--;
//             if (vals[a]>vals[b]) cnt--;
//             if(right[b]!=-1&& vals[b]>vals[right[b]]) cnt--;
//             vals[a]=val;
//             right[a]=right[b];
//             if(right[b]!=-1 ) left[right[b]]=a;
//             if(left[a]!=-1&&vals[left[a]]>vals[a]){
//                 cnt++;
//             o.insert({
//                 vals[left[a]]+vals[a],left[a]
//             });
//             }
//             if (right[a]!=-1 && vals[a]>vals[right[a]]){
//                 cnt++;
//             o.insert({
//                 vals[a]+vals[right[a]],a
//             });
//             }
//         }
//         return upd;
//     }// };


//  ....
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<long long> a(nums.begin(), nums.end());
        int inv = 0;
        for (int i = 0; i < n - 1; i++) if (a[i] > a[i + 1]) inv++;

        set<int> idx;
        for (int i = 0; i < n; i++) idx.insert(i);

        set<pair<long long,int>> s;
        for (int i = 0; i < n - 1; i++) s.insert({a[i]+a[i+1], i});

        while (inv > 0) {
            ans++;
            auto it = s.begin();
            long long val = it->first;
            int i = it->second;
            s.erase(it);

            auto j_it = idx.upper_bound(i);
            int j = *j_it;

            if (a[i] > a[j]) inv--;

            auto i_it = idx.find(i);
            if (i_it != idx.begin()) {
                auto h_it = prev(i_it);
                int h = *h_it;

                if (a[h] > a[i]) inv--;
                s.erase({a[h]+a[i], h});
                if (a[h] > val) inv++;
                s.insert({a[h]+val, h});
            }

            auto k_it = next(j_it);
            if (k_it != idx.end()) {
                int k = *k_it;
                if (a[j] > a[k]) inv--;
                s.erase({a[j]+a[k], j});
                if (val > a[k]) inv++;
                s.insert({val + a[k], i});
            }

            a[i] = val;
            idx.erase(j);
        }

        return ans;
    }
};
