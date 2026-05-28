class Solution {
public:
struct Trie {
        int nxt[26];
        int idx, len;

        Trie() {
            memset(nxt, 0, sizeof(nxt));
            idx = 1e9;
            len = 1e9;
        }
    };

    vector<Trie> tr;

    void insert(string &s, int idx) {

        int curr = 0;

        if(tr[curr].len > s.size()) {
            tr[curr].len = s.size();
            tr[curr].idx = idx;
        }

        for(char c : s) {

            int val = c - 'a';

            if(!tr[curr].nxt[val]) {

                tr[curr].nxt[val] = tr.size();

                tr.push_back(Trie());
            }

            curr = tr[curr].nxt[val];

            if(tr[curr].len > s.size()) {
                tr[curr].len = s.size();
                tr[curr].idx = idx;
            }
        }
    }

    int find(string &s) {

        int curr = 0;

        for(char c : s) {

            int val = c - 'a';

            if(!tr[curr].nxt[val]) {
                break;
            }

            curr = tr[curr].nxt[val];
        }

        return tr[curr].idx;
    }

    vector<int> stringIndices(vector<string>& a, vector<string>& b) {

        tr.push_back(Trie());

        for(int i = 0; i < a.size(); i++) {

            reverse(a[i].begin(), a[i].end());

            insert(a[i], i);
        }

        vector<int> nums;

        for(auto &i : b) {

            reverse(i.begin(), i.end());

            nums.push_back(find(i));
        }

        return nums;
    }
};
//  I copy it after getting mle