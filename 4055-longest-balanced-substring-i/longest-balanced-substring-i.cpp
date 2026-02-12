// class Solution {
// public:
//     int longestBalanced(string s) {
//         int n=s.size();
//         int ans=0;
//         for(int i=0;i<n;i++){
//             vector<int> freq(26,0);
//             for(int j=i;j<n;j++){
//                 freq[s[j]-'a']++;
//                 unordered_set<int>st;
//                 for(int k=0;k<26;k++){
//                     if(freq[k]>0)
//                         st.insert(freq[k]);
//                 }
//                 if(st.size()==1)
//                     ans=max(ans,j-i+1);
//             }
//         }
//         return ans;
        
//     }
// };
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            int distinct = 0;
            int maxFreq = 0;

            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';

                if (freq[idx] == 0)
                    distinct++;

                freq[idx]++;
                maxFreq = max(maxFreq, freq[idx]);

                if (maxFreq * distinct == j - i + 1)
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};