class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string,string> lower, vowel;

        auto toLower = [](string w) {
            transform(w.begin(), w.end(), w.begin(), ::tolower);
            return w;
        };

        auto mask = [&](string w) {
            w = toLower(w);
            for (char &c : w) if (string("aeiou").find(c) != string::npos) c = '*';
            return w;
        };

        for (auto &w : wordlist) {
            string lw = toLower(w);
            lower.try_emplace(lw, w);
            vowel.try_emplace(mask(w), w);
        }

        vector<string> res;
        for (auto &q : queries) {
            if (exact.count(q)) { res.push_back(q); continue; }
            string lq = toLower(q);
            if (lower.count(lq)) { res.push_back(lower[lq]); continue; }
            res.push_back(vowel.count(mask(q)) ? vowel[mask(q)] : "");
        }
        return res;
    }
};