// class Solution {
// public:
//     vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
//         int n=positions.size();
//         vector<pair<int,vector<int>>>v(n);
//         for(int i=0;i<n;i++){
//             v[i]={positions[i],{i,healths[i],directions[i]}};
//         }
//         sort(v.begin(),v.end());
//         stack<pair<int,vector<int>>>st;
//         vector<pair<int,vector<int>>>ans;
//         for(int i=0;i<n;i++){
//             if(v[i].second[2]=='R'){
//                 st.push(v[i]);
//             } else{
//                 bool ok=true;
//                 while(!st.empty()){
//                     pair<int,vector<int>> tp=st.top();
//                     st.pop();
//                     if(tp.second[1]==v[i].second[1]){
//                         ok=false;
//                         break;
//                     }else if(tp.second[1]>v[i].second[1]){
//                         ok=false;
//                         tp.second[1]--;
//                         st.push(tp);
//                         break;
//                     }else{
//                         v[i].second[1]--;
//                         continue;
//                     }
//                 }
//                 if(ok){
//                     ans.push_back(v[i]);
//                 }
//             }

//         }
//         while(!st.empty()){
//             ans.push_back(st.top());
//             st.pop();
//         }
//         for(int i=0;i<ans.size();i++){
//             pair<int,vector<int>>temp=ans[i];
//             ans[i].first=temp.second[0];
//             ans[i].second[0]=temp.first;
//         }
//         sort(ans.begin(),ans.end());
//         vector<int>res;
//         for(int i=0;i<ans.size();i++){
//             res.push_back(ans[i].second[1]);
//         }
//         return res;
        
//     }
// };
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        vector<int> stk;

        for (int i : idx) {
            if (directions[i] == 'R') {
                stk.push_back(i);
                continue;
            }

            while (!stk.empty() && healths[i] > 0) {
                int j = stk.back();

                if (healths[j] > healths[i]) {
                    healths[j]--;
                    healths[i] = 0;
                } else if (healths[j] < healths[i]) {
                    healths[i]--;
                    healths[j] = 0;
                    stk.pop_back();
                } else {
                    healths[i] = healths[j] = 0;
                    stk.pop_back();
                    break;
                }
            }
        }

        vector<int> ans;
        for (int h : healths) {
            if (h > 0) {
                ans.push_back(h);
            }
        }
        return ans;
    }
};