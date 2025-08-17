class Solution {
public:
    double new21Game(int a, int b, int c) {
        vector<double> d(b);
        function<double(int)> e = [&](int f) -> double {
            if (f >= b) return f <= a ? 1 : 0;
            if (f == b - 1) return min(a - b + 1, c) * 1.0 / c;
            if (d[f]) return d[f];
            return d[f] = e(f + 1) + (e(f + 1) - e(f + c + 1)) / c;
        };
        
        return e(0);
    }
};
