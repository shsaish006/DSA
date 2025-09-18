class TaskManager {
    unordered_map<int, pair<int,int>> d;
    priority_queue<tuple<int,int,int>> pq;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) add(t[0], t[1], t[2]);
    }

    void add(int u, int id, int p) {
        d[id] = {u,p};
        pq.push({p,id,u});
    }

    void edit(int id, int p) {
        auto [u,old] = d[id];
        d[id] = {u,p};
        pq.push({p,id,u});
    }

    void rmv(int id) {
        d.erase(id);
    }

    int execTop() {
        while (!pq.empty()) {
            auto [p,id,u] = pq.top();
            if (!d.count(id) || d[id].second != p) { pq.pop(); continue; }
            pq.pop();
            d.erase(id);
            return u;
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */