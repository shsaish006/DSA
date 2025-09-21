class MovieRentingSystem {
    unordered_map<int, set<pair<int,int>>> avail;
    unordered_map<long long,int> mp;
    set<tuple<int,int,int>> rented;

    long long key(int s,int m) {
        return ((long long)s<<30)|m;
    }

public:
    MovieRentingSystem(int n, vector<vector<int>>& e) {
        for (auto& x:e) {
            avail[x[1]].insert({x[2],x[0]});
            mp[key(x[0],x[1])] = x[2];
        }
    }

    vector<int> search(int m) {
        vector<int> r;
        if (!avail.count(m)) return r;
        int c=0;
        for (auto& [p,s]:avail[m]) {
            r.push_back(s);
            if (++c==5) break;
        }
        return r;
    }

    void rent(int s,int m) {
        int p=mp[key(s,m)];
        avail[m].erase({p,s});
        rented.insert({p,s,m});
    }

    void drop(int s,int m) {
        int p=mp[key(s,m)];
        rented.erase({p,s,m});
        avail[m].insert({p,s});
    }

    vector<vector<int>> report() {
        vector<vector<int>> r;
        int c=0;
        for (auto& [p,s,m]:rented) {
            r.push_back({s,m});
            if (++c==5) break;
        }
        return r;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */