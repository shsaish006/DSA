class Router {
    int memoryLimit;
    deque<tuple<int,int,int>> fifo; // store packets in arrival order
    unordered_set<string> packetSet; // to check duplicates
    unordered_map<int, vector<int>> destMap; // destination -> timestamps sorted (monotonic)
    
    string key(int s, int d, int t) {
        return to_string(s) + "#" + to_string(d) + "#" + to_string(t);
    }
    
public:
    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        string k = key(source, destination, timestamp);
        if(packetSet.count(k)) return false;
        
        // remove oldest if memory exceeds
        if(fifo.size() == memoryLimit) {
            auto [os, od, ot] = fifo.front();
            fifo.pop_front();
            string oldKey = key(os, od, ot);
            packetSet.erase(oldKey);
            
            // remove timestamp from destMap[od]
            auto &vec = destMap[od];
            vec.erase(vec.begin());
            if(vec.empty()) destMap.erase(od);
        }
        
        fifo.push_back({source,destination,timestamp});
        packetSet.insert(k);
        destMap[destination].push_back(timestamp); // append since timestamps increase
        return true;
    }
    
    vector<int> forwardPacket() {
        if(fifo.empty()) return {};
        auto [s,d,t] = fifo.front();
        fifo.pop_front();
        packetSet.erase(key(s,d,t));
        auto &vec = destMap[d];
        vec.erase(vec.begin());
        if(vec.empty()) destMap.erase(d);
        return {s,d,t};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if(destMap.find(destination) == destMap.end()) return 0;
        auto &vec = destMap[destination];
        // vec is sorted, use lower_bound and upper_bound
        auto l = lower_bound(vec.begin(), vec.end(), startTime);
        auto r = upper_bound(vec.begin(), vec.end(), endTime);
        return r - l;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
