class Solution {
public:
    map<int,int> f[10] = {
        {}, {}, {{2,1}}, {{3,1}}, {{2,2}}, {{5,1}},
        {{2,1},{3,1}}, {{7,1}}, {{2,3}}, {{3,2}}
    };

    map<int,int> get(long long t, bool &ok) {
        map<int,int> c{{2,0},{3,0},{5,0},{7,0}};
        for (int p : {2,3,5,7})
            while (t % p == 0)
                t /= p, c[p]++;
        ok = t == 1;
        return c;
    }

    map<int,int> get(string s) {
        map<int,int> c{{2,0},{3,0},{5,0},{7,0}};
        for (char d : s)
            for (auto [p,x] : f[d-'0'])
                c[p] += x;
        return c;
    }

    map<int,int> make(map<int,int> c) {
        map<int,int> r;
        int a = c[2] / 3, b = c[2] % 3;
        int d = c[3] / 2, e = c[3] % 2;
        int g = b / 2, h = b % 2, z = 0;

        if (h && e)
            h = e = 0, z = 1;

        if (e && g)
            h = 1, z = 1, e = g = 0;

        r[2]=h;
        r[3]=e;
        r[4]=g;
        r[5]=c[5];
        r[6]=z;
        r[7]=c[7];
        r[8]=a;
        r[9]=d;

        return r;
    }

    map<int,int> sub(map<int,int> a, map<int,int> b) {
        for (auto [k,v] : b)
            a[k] = max(0, a[k]-v);
        return a;
    }

    int sum(map<int,int> a) {
        int s = 0;
        for (auto [k,v] : a)
            s += v;
        return s;
    }

    bool ok(map<int,int> a, map<int,int> b) {
        for (auto [k,v] : a)
            if (b[k] < v)
                return false;
        return true;
    }

    string build(map<int,int> a) {
        string s;
        for (int i=2;i<10;i++)
            s += string(a[i],char('0'+i));
        return s;
    }

    string smallestNumber(string num, long long t) {
        bool good;
        auto need = get(t,good);

        if (!good)
            return "-1";

        auto fac = make(need);

        if (sum(fac) > num.size())
            return build(fac);

        auto pre = get(num);
        int z = num.find('0');

        if (z == string::npos) {
            z = num.size();
            if (ok(need,pre))
                return num;
        }

        for (int i=num.size()-1;i>=0;i--) {
            int d = num[i]-'0';
            pre = sub(pre,f[d]);

            int space = num.size()-1-i;

            if (i > z)
                continue;

            for (int x=d+1;x<10;x++) {
                auto rem = sub(sub(need,pre),f[x]);
                auto cur = make(rem);

                if (sum(cur) <= space) {
                    int ones = space-sum(cur);
                    return num.substr(0,i) +
                           char('0'+x) +
                           string(ones,'1') +
                           build(cur);
                }
            }
        }

        fac = make(need);
        return string(num.size()+1-sum(fac),'1') + build(fac);
    }
};