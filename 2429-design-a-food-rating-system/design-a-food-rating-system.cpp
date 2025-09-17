class FoodRatings {
    unordered_map<string, set<pair<int, string>>> d;
    unordered_map<string, pair<int, string>> g;
public:
    FoodRatings(vector<string>& f, vector<string>& c, vector<int>& r) {
        for (int i = 0; i < f.size(); i++) {
            d[c[i]].insert({-r[i], f[i]});
            g[f[i]] = {r[i], c[i]};
        }
    }
    void changeRating(string food, int nr) {
        auto [or_, c] = g[food];
        g[food] = {nr, c};
        d[c].erase({-or_, food});
        d[c].insert({-nr, food});
    }
    string highestRated(string c) {
        return d[c].begin()->second;
    }
};


/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */