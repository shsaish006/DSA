class Robot {
public:
    int a, b, c, d;
    bool s;

    Robot(int width, int height) {
        a = width - 1;
        b = height - 1;
        c = 2 * (a + b);
        d = 0;
        s = 0;
    }

    void step(int num) {
        s = 1;
        d = (d + num) % c;
    }

    vector<int> getPos() {
        if (d <= a) return {d, 0};
        if (d <= a + b) return {a, d - a};
        if (d <= a + b + a) return {a - (d - a - b), b};
        return {0, b - (d - a - b - a)};
    }

    string getDir() {
        if (!s) return "East";
        if (d == 0) return "South";
        if (d <= a) return "East";
        if (d <= a + b) return "North";
        if (d <= a + b + a) return "West";
        return "South";
    }};