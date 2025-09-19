class Spreadsheet {
    unordered_map<string, int> d;
public:
    Spreadsheet(int) {}
    void setCell(string c, int v) { d[c] = v; }
    void resetCell(string c) { d.erase(c); }
    int getValue(string f) {
        int r = 0;
        string t;
        stringstream ss(f.substr(1));
        while (getline(ss, t, '+')) r += isdigit(t[0]) ? stoi(t) : d[t];
        return r;
    }
};


/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */