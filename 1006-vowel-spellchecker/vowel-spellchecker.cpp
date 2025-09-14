class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string,string> lower, vowel;

        auto mask = [](string w) {
            for (char &c : w) {
                c = tolower(c);
                if (string("aeiou").find(c) != string::npos) c = '*';
            }
            return w;
        };

        for (auto &w : wordlist) {
            string lw = w; transform(lw.begin(), lw.end(), lw.begin(), ::tolower);
            lower.emplace(lw, w);
            vowel.emplace(mask(lw), w);
        }

        vector<string> res;
        for (auto q : queries) {
            if (exact.count(q)) { res.push_back(q); continue; }
            string lq = q; transform(lq.begin(), lq.end(), lq.begin(), ::tolower);
            if (lower.count(lq)) { res.push_back(lower[lq]); continue; }
            string mq = mask(lq);
            res.push_back(vowel.count(mq) ? vowel[mq] : "");
        }
        return res;
    }
};
