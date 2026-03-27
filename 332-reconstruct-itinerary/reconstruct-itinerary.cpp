class Solution {
public:
    unordered_map<string, vector<string>>g;
    vector<string> ans;
    void dfs(string a){
        while(g[a].size()){
            string b=g[a].back();
            g[a].pop_back();
            dfs(b);
        }
        ans.push_back(a);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(),tickets.end());
        for(int i=tickets.size()-1;i>=0;i--){
            g[tickets[i][0]].push_back(tickets[i][1]);
        }
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};