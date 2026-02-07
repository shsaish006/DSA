// class Solution {
// public:
//     int minimumDeletions(string s) {
//         int n=s.size();
//         stack<int>st;
//         int count=0;
//         for(int i=0;i<n;i++){
//             if(s[i]=='a'){
//                 if(!st.empty()){
//                     count++;
//                     st.pop();
//                 }
//             }else{
//                 st.push('b');
//             }
//         }
//         return count;
        
//     }
// };
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int f[n + 1];
        memset(f, 0, sizeof(f));
        int b = 0;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] == 'b') {
                f[i] = f[i - 1];
                ++b;
            } else {
                f[i] = min(f[i - 1] + 1, b);
            }
        }
        return f[n];
    }
};