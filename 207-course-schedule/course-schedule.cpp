class Solution {
public:
//  n= numCourses , p= prerequisites
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> g(n);
        vector<int> d(n);
        queue<int> q;
        for(auto &i:p) g[i[1]].push_back(i[0]), d[i[0]]++;
        for(int i=0;i<n;i++) if(!d[i]) q.push(i);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            n--;
            for(int y:g[x])
            if(!--d[y]) q.push(y);
        }
        return !n;
    }
};
//  yaha per logic hain kahns algo /bfs topo sort sabse pehle graph built karenge create edge b->a meaning course a must complete b first d[a]++ store karenge indegree ko 
// phir course jaha no pre.. immediately le sajte hain aur phir push karneg queue mein remove one decrese by n y dependes on x decrese indegree and indegree 0 ho becomes 0 all pre finished push karo queue mwin har course processed n zero ho jayega 