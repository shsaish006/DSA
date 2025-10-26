class Bank {
    vector<long long> a;
public:
    Bank(vector<long long>& balance) : a(balance) {}

    bool transfer(int b, int c, long long d) {
        if (b < 1 || c < 1 || b > a.size() || c > a.size() || a[b-1] < d) return false;
        a[b-1] -= d;
        a[c-1] += d;
        return true;
    }

    bool deposit(int b, long long d) {
        if (b < 1 || b > a.size()) return false;
        a[b-1] += d;
        return true;
    }

    bool withdraw(int b, long long d) {
        if (b < 1 || b > a.size() || a[b-1] < d) return false;
        a[b-1] -= d;
        return true;
    }
};