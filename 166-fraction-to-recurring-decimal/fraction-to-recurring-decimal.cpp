class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (!numerator) return "0";
        string res;
        if ((numerator < 0) ^ (denominator < 0)) res += "-";
        long long a = llabs((long long)numerator), b = llabs((long long)denominator);
        res += to_string(a / b);
        a %= b;
        if (!a) return res;
        res += ".";
        unordered_map<long long,int> mp;
        while (a) {
            if (mp.count(a)) {
                res.insert(mp[a], "(");
                res += ")";
                break;
            }
            mp[a] = res.size();
            a *= 10;
            res += to_string(a / b);
            a %= b;
        }
        return res;
    }
};