class Solution {
public:
    int findMinStep(string board, string hand) {
        vector<int> freq(26, 0);
        for(char c: hand)
            freq[c - 'A']++;

        unordered_map<string, int> dp;
        return dfs(board, freq, dp);
    }

    int dfs(string b, vector<int>& freq, unordered_map<string,int>& dp) {
        string key = b + "#" + get(freq);
        if(dp.count(key)) return dp[key];

        if(b.empty()) return dp[key] = 0;

        int ans = INT_MAX;

        for(int i = 0; i < b.size(); i++){
            for(int j = 0; j < 26; j++){

                bool ok = false;

                if(b[i] - 'A' == j)
                    ok = true;
                else if(i > 0 && b[i] == b[i-1] && b[i] - 'A' != j)
                    ok = true;

                if(freq[j] > 0 && ok){

                    b.insert(b.begin() + i, char(j + 'A'));
                    freq[j]--;

                    string nb = shrink(b);
                    int val = dfs(nb, freq, dp);

                    if(val != -1)
                        ans = min(ans, val + 1);

                    freq[j]++;
                    b.erase(b.begin() + i);
                }
            }
        }

        return dp[key] = (ans == INT_MAX ? -1 : ans);
    }

    string shrink(string s){
        for(int i = 0; i < s.size(); ){
            int j = i;
            while(j < s.size() && s[j] == s[i]) j++;

            if(j - i >= 3)
                return shrink(s.substr(0,i) + s.substr(j));

            i = j;
        }
        return s;
    }

    string get(vector<int>& freq){
        string s = "";
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0){
                s += char(i + 'A');
                s += to_string(freq[i]);
            }
        }
        return s;
    }
};